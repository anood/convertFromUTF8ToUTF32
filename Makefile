CXXFLAGS= `pkg-config --cflags  icu-uc icu-io`
LDLIBS=`pkg-config --libs  icu-uc icu-io` 
all: convert
