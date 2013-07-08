CC=g++
POLYCODEFOLDER=../Polycode/Release/Linux/Framework

CPPFLAGS=-std=c++11 -pthread -I$(POLYCODEFOLDER)/Core/Dependencies/include -I$(POLYCODEFOLDER)/Core/Dependencies/include/AL -I$(POLYCODEFOLDER)/Core/include -I$(POLYCODEFOLDER)/Modules/include -I$(POLYCODEFOLDER)/Modules/Dependencies/include -I$(POLYCODEFOLDER)/Modules/Dependencies/include/bullet
LDFLAGS=-lrt -ldl -lpthread $(POLYCODEFOLDER)/Core/lib/libPolycore.a $(POLYCODEFOLDER)/Core/Dependencies/lib/libfreetype.a $(POLYCODEFOLDER)/Core/Dependencies/lib/liblibvorbisfile.a $(POLYCODEFOLDER)/Core/Dependencies/lib/liblibvorbis.a $(POLYCODEFOLDER)/Core/Dependencies/lib/liblibogg.a $(POLYCODEFOLDER)/Core/Dependencies/lib/libopenal.so $(POLYCODEFOLDER)/Core/Dependencies/lib/libphysfs.a $(POLYCODEFOLDER)/Core/Dependencies/lib/libpng15.a $(POLYCODEFOLDER)/Core/Dependencies/lib/libz.a -lGL -lGLU -lSDL $(POLYCODEFOLDER)/Modules/lib/libPolycode2DPhysics.a $(POLYCODEFOLDER)/Modules/Dependencies/lib/libBox2D.a $(POLYCODEFOLDER)/Modules/lib/libPolycode3DPhysics.a $(POLYCODEFOLDER)/Modules/Dependencies/lib/libBulletDynamics.a $(POLYCODEFOLDER)/Modules/Dependencies/lib/libBulletCollision.a $(POLYCODEFOLDER)/Modules/Dependencies/lib/libLinearMath.a

SOURCES = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
OBJECTS := ${SOURCES:.cpp=.o}

.PHONY: all clean

all: pewpew doc

pewpew: $(OBJECTS)
	$(CC) $(CPPFLAGS) $(OBJECTS) -o pewpew $(LDFLAGS)

doc:
	doxygen Doxygen.conf
clean:
	@- $(RM) $(OBJECTS) pewpew 
	@- $(RM) -r html
	@- $(RM) -r latex