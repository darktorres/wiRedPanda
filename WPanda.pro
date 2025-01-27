TEMPLATE = subdirs
SUBDIRS = common app test

app.depends = common
test.depends = common
