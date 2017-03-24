QT += widgets

HEADERS     = \
              window.h \

SOURCES     = \
              window.cpp \
              main.cpp \

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets
INSTALLS += target

DISTFILES += \
    dog.jpg \
    betty.jpg \
    cat.jpg \
    dog.png
