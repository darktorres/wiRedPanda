FROM ubuntu:20.04

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive \
    QT_VERSION=5.15.2 \
    QT_DIR=/root/Qt

# Install required dependencies
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    curl \
    git \
    jq \
    libcurl4-openssl-dev \
    libfontconfig1-dev \
    libfreetype6-dev \
    libfuse2 \
    libgl1-mesa-dev \
    libgstreamer-gl1.0-0 \
    libpulse-dev \
    libx11-dev \
    libx11-xcb-dev \
    libxcb-glx0-dev \
    libxcb-icccm4-dev \
    libxcb-image0-dev \
    libxcb-keysyms1-dev \
    libxcb-randr0-dev \
    libxcb-render-util0-dev \
    libxcb-shape0-dev \
    libxcb-shm0-dev \
    libxcb-sync0-dev \
    libxcb-xfixes0-dev \
    libxcb-xinerama0 \
    libxcb1-dev \
    libxext-dev \
    libxfixes-dev \
    libxi-dev \
    libxkbcommon-dev \
    libxkbcommon-x11-dev \
    libxrender-dev \
    patchelf \
    python3 \
    python3-dev \
    python3-pip \
    python3-venv \
    wget \
    && apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Set up Python virtual environment
RUN python3 -m venv /root/venv && \
    /root/venv/bin/pip install --no-cache-dir --upgrade pip setuptools wheel && \
    /root/venv/bin/pip install --no-cache-dir aqtinstall==3.1.*

# Install Qt using aqtinstall
RUN /root/venv/bin/aqt install-qt linux desktop $QT_VERSION --outputdir $QT_DIR

# Update PATH to include Qt binaries
ENV PATH="$QT_DIR/$QT_VERSION/gcc_64/bin:$PATH"

# Install and compile Sentry SDK
RUN git clone --recursive https://github.com/getsentry/sentry-native.git && \
    mkdir -p sentry-native/build && \
    cd sentry-native/build && \
    cmake .. -B build -D SENTRY_BACKEND=crashpad -D CMAKE_BUILD_TYPE=RelWithDebInfo && \
    cmake --build build --parallel && \
    cmake --install build --prefix ../../thirdparty/sentry && \
    cd ../..

# Clone the WiredPanda repository
RUN git clone --recursive https://github.com/darktorres/wiredpanda

# Build WiredPanda
RUN mkdir -p /wiredpanda/build && \
    cd /wiredpanda/build && \
    qmake ../WPanda.pro && \
    make -j4 && \
    cp ../thirdparty/sentry/bin/crashpad_handler ./app && \
    cp ../thirdparty/sentry/lib/libsentry.so ./app && \
    cp ../thirdparty/sentry/lib/libsentry.so ./test && \
    cd ../..

# Run Tests
RUN cd /wiredpanda/build/test && ./WPanda-test -platform offscreen && cd ../../..

# Install linuxdeployqt and create AppImage
RUN mkdir /wiredpanda/appimage && \
    cp /wiredpanda/app/resources/wpanda.desktop /wiredpanda/appimage/wpanda.desktop && \
    cp /wiredpanda/app/resources/wpanda.svg /wiredpanda/appimage/wpanda_icon.svg && \
    cp /wiredpanda/build/app/wiredpanda /wiredpanda/appimage && \
    cp /wiredpanda/thirdparty/sentry/lib/libsentry.so /wiredpanda/appimage && \
    cp /wiredpanda/thirdparty/sentry/lib/libsentry.so /wiredpanda/appimage/lib && \
    wget https://github.com/probonopd/linuxdeployqt/releases/download/continuous/linuxdeployqt-continuous-x86_64.AppImage && \
    chmod +x ./linuxdeployqt-continuous-x86_64.AppImage && \
    VERSION=latest ./linuxdeployqt-continuous-x86_64.AppImage /wiredpanda/appimage/wiredpanda -appimage && \
    rm ./linuxdeployqt-continuous-x86_64.AppImage && \
    mv wiRedPanda-latest-x86_64.AppImage wiRedPanda-latest-Ubuntu-Qt5.AppImage

# Set default working directory
WORKDIR /wiredpanda/build

# Keep the container running
CMD ["tail", "-f", "/dev/null"]
