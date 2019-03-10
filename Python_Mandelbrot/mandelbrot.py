# Set parameters
# Create plane
# Run each point through zFunction
# Count iterations
# Make rbg array
# Create png from array

import math
from PIL import Image


sizes   = [-2.0, -2.0, 2.0, 2.0]   # [minX, minY, maxX, maxY]
res     = [500, 500]
maxIter = 100

plane   = [ [0]*res[0] ]*res[1]
xSpace  = sizes[2] - sizes[0]
ySpace  = sizes[3] - sizes[1]


def planeCoords(i, j):
    global xSpace, ySpace, res, sizes
    #x = i * xSpace/res[0] - sizes[0]
    #y = j * ySpace/res[1] - sizes[1]
    x = i/(res[0]/xSpace) + sizes[0]
    y = j/(res[1]/ySpace) + sizes[1]
    #print(x, y)
    #y = j/25 - 2
    return [x, y]


def zFunc(z, c):
    Re = z[0]**2 - z[1]**2 + c[0]
    Im = 2 * z[0] * z[1] + c[1]
    return [Re, Im]


def inPlane(z):
    if math.sqrt(z[0]**2 + z[1]**2) > 2:
        return False
    return True


def getIterations(c):
    z = c
    k = 0
    for k in range(maxIter):
        
        z = zFunc(z, c)
        if not inPlane(z):
            return k
    return -1


def getColor(iterations):
    r = 0
    g = 0
    b = 0
    if k >= 0:
        b = k*5 + 100
        if b > 255:
            r = 255
            g = 255
            b = 255
    return (r, g, b)
#            r = b - 255
#            g = b - 255
#            b = 255
#            if r > 255 or g > 255:
#                r = 255
#                g = 255

#            g = b - 255
#            if g > 255:
#                r = g - 255
#                if r > 255:
#                   r = 255
#                g = 255
#            b = 255


# Create rgb image array.
rgb = []# * res[0] * res[1]
for i in range(res[0]):
    for j in range(res[1]):
        c = planeCoords(j, i)
        k = getIterations(c)
        rgb.append(getColor(k))


im = Image.new("RGB", (res[0], res[1]), color=0)
im.putdata(rgb)
im.save("img.png")
im.show()
