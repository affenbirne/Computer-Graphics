
EXEC = rasterizer

# Determine the plaform architecture
ifeq ($(shell uname -m), x86_64)
	PLATFORM := x64
	BITS := 64d
else
	PLATFORM := x86
	BITS := 32
endif

CC        = g++ 
CXX		  = g++ 
CFLAGS    +=  -g -O3 -DLINUX  #-Wall

LFLAGS    += -L/usr/X11R6/lib -lX11
INCLUDES  =  -I. -Iinclude -Iglm -I/usr/X11R6/include 


OBJS = src/main.o src/Windowing/DisplayWindow.o src/Rasterizer/SimpleRasterizer.o src/Raytracer/Accelerator.o src/Raytracer/SimpleAccelerator.o src/Raytracer/Image.o src/Raytracer/PhongIntegrator.o src/Raytracer/Ray.o src/Raytracer/SimpleRenderer.o src/Raytracer/Renderer.o src/Raytracer/RayHit.o src/Raytracer/Objects/Mesh.o src/Raytracer/Objects/Sphere.o src/Raytracer/Objects/Triangle.o src/Raytracer/Scenes/Intersection.o src/Raytracer/Scenes/Scene.o src/Raytracer/Scenes/PhysicalObject.o src/Raytracer/Scenes/Camera.o src/Raytracer/Scenes/Material.o src/Raytracer/Scenes/SceneObject.o src/Raytracer/Scenes/Light.o src/Raytracer/Scenes/PointLight.o 


$(EXEC) : $(OBJS) 
	$(CXX) -o $(EXEC) $(OBJS) $(CFLAGS) $(LIBS) $(LFLAGS) 

all: $(OBJS)

$(OBJS): %.o: %.cpp
	$(CXX) -c $(CFLAGS) $(INCLUDES) $< -o $@

gl3w/src/gl3w.o: %.o: %.c
	$(CXX) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean::
	rm -f $(EXEC) *.o *~ core tags src/*.o src/Rasterizer/*.o src/Windowing/*.o src/Raytracer/Scenes/*.o src/Raytracer/*.o src/Raytracer/Objects/*.o
