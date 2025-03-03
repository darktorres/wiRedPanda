FROM ubuntu:latest

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive \
    QT_VERSION=5.15.2 \
    QT_DIR=/root/Qt

# Install required dependencies
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    libgl1-mesa-dev \
    libxcb-xinerama0 \
    libpulse-dev \
    git \
    python3 \
    python3-pip \
    python3-venv \
    build-essential \
    qt5-qmake && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Set up Python virtual environment
RUN python3 -m venv /root/venv && \
    /root/venv/bin/pip install --no-cache-dir aqtinstall==3.1.*

# Install Qt using aqtinstall
RUN /root/venv/bin/aqt install-qt linux desktop $QT_VERSION --outputdir $QT_DIR

# Update PATH to include Qt binaries
ENV PATH="$QT_DIR/$QT_VERSION/gcc_64/bin:$PATH"

# Clone the WiredPanda repository and build
RUN git clone https://github.com/GIBIS-UNIFESP/wiredpanda && \
    mkdir -p wiredpanda/build && \
    cd wiredpanda/build && \
    qmake ../WPanda.pro && \
    make -j

# Set default working directory
WORKDIR /wiredpanda/build

# Keep the container running
CMD ["tail", "-f", "/dev/null"]