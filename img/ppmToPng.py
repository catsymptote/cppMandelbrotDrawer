from PIL import Image
import sys
from time import sleep


img = open("img.ppm")

if(img.readline() == "P3" or True):
    pixel_matrix = []
    """
    size_x, size_y = img.readline().split()
    color = img.readline()
    
    sX = int(size_x)
    sY = int(size_y)

    print(pixel_matrix)
    print(sX)
    print(sY)
    print(color)
    """

    x = 0
    y = 0
    z = 0
    percentInt = 0
    
    #while(there are lines left):
    print("Open file..")
    with open("img.ppm") as f:
        magicNumber     = f.readline()
        size_x, size_y  = f.readline().split()
        sX              = int(size_x)
        sY              = int(size_y)
        color           = int(f.readline())
        pixel_row = []
        print("Reading file..")
        print("####################")
        for line in f:
            pixel = line.split()
            pixel_row.append(pixel)
            pixel = []

            if(not x < sX -0):
                pixel_matrix.append(pixel_row)
                pixel_row = []
                #print(pixel_row)
                y += 1
                x = 0
                if(100*z/(sX*sY) > percentInt):
                    #print(str(percentInt) + "%")
                    sys.stdout.write("#")
                    sys.stdout.flush()
                    percentInt += 5
            x += 1
            z += 1
    print("\nFile read")
    #print("sX, sY")
    #print(sX)
    #print(sY)
    
    #print("x, y, z")
    #print(x)
    #print(y)
    #print(z)

    png_img = Image.new('RGB', (sX -1, sY -1), (0, 0, 0))
    png_pix = png_img.load()
    print("New file created and loaded\n")
    #png_img.putdata(pixel_matrix)

    #print("lenPix, lenPix[x]")
    #print(len(pixel_matrix))
    #print(len(pixel_matrix[0]))
    #print(pixel_matrix[len(pixel_matrix) -1])
    #print(pixel_matrix[0])
    #print()
    z = 0
    percentInt = 0
    print("Writing file..")
    print("####################")
    for y in range(sY -1):
        for x in range(sX -1):
            if(100*z/(sX*sY) > percentInt):
                #print(str(percentInt) + "%")
                sys.stdout.write("#")
                sys.stdout.flush()
                percentInt += 5
            #cake = pixel_matrix[y][x]
            #print(cake)
            #cookie = (int(cake[0]), int(cake[1]), int(cake[2]))
            #print(cookie)
            #png_pix[x, y] = cookie
            #png_pix[x, y] = list(map(int, pixel_matrix[x][y]))
            #print(x)
            #print(y)
            #print(int(pixel_matrix[y][x][0]))
            #print(int(pixel_matrix[y][x][1]))
            #rint(int(pixel_matrix[y][x][2]))
            #print()
            mep = (int(pixel_matrix[y][x][0]), int(pixel_matrix[y][x][1]), int(pixel_matrix[y][x][2]))
            #print(mep)
            png_pix[x, y] = mep
            z += 1
    print("\nSaving file..")
    png_img.save("img.png")
    print("File written")
    print("Script closing")
    sleep(1)









    """
    with open("img.ppm") as fp:
        for line in fp:
            r, g, b = line.split(' ')

            print(line)
            sys.stdout.flush()
    """


#size_x = f.readline()
#size_y = f.readline()
#color = f.readline().splitlines()




#img = Image.open("img.ppm")
#img.save("img.png")



"""
import io


ppmtxt = '''P3
# feep.ppm
4 4
15
 0  0  0    0  0  0    0  0  0   15  0 15
 0  0  0    0 15  7    0  0  0    0  0  0
 0  0  0    0  0  0    0 15  7    0  0  0
15  0 15    0  0  0    0  0  0    0  0  0
'''


def tokenize(f):
    for line in f:
        if line[0] != '#':
            for t in line.split():
                yield t

def ppmp3tobitmap(f):
    t = tokenize(f)
    nexttoken = lambda : next(t)
    assert 'P3' == nexttoken(), 'Wrong filetype'
    width, height, maxval = (int(nexttoken()) for i in range(3))
    bitmap = Bitmap(width, height, Colour(0, 0, 0))
    for h in range(height-1, -1, -1):
        for w in range(0, width):
            bitmap.set(w, h, Colour( *(int(nexttoken()) for i in range(3))))
 
    return bitmap


print('Original Colour PPM file')
print(ppmtxt)
ppmfile = io.StringIO(ppmtxt)
bitmap = ppmp3tobitmap(ppmfile)
print('Grey PPM:')
bitmap.togreyscale()
ppmfileout = io.StringIO('')
bitmap.writeppmp3(ppmfileout)
print(ppmfileout.getvalue())


img = ppmp3tobitmap()
img.save(img.png)
"""