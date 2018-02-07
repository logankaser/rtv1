# 42 RTv1
A simple raytracer in C, with diffusion and shadows.

![Screenshot](https://raw.githubusercontent.com/logankaser/rtv1/master/example.png)

Scenes are descripbed by a simple format:  
camera from<val, val, val> to<val, val ,val>  
For example:
`camera 5 0 0 0 1 0`
We support 4 primatives, spheres, planes, cylinders, and cones.  
```
sphere <position> <radius> <color>  
plane <position> <vector> <color>  
cylinder <position> <vector> <radius> <color>  
cone <position> <vector> <angle> <color>
```
where
position is a vec3 ex: `1 0 1`  
radius is a real number ex: `0.5`  
color is a hexdecimal color ex: `0xFFFFFF`  
vector is a vec3 ex: `1 0 1`  
angle is a real number ex: `45`  
