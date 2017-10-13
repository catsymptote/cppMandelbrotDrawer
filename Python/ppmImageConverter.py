from PIL import Image


def ppm_p3_to_array(img_path):
    pass


def png_to_array(img_path):
    img = Image.open(img_path)
    pix_array = img.load()
    return pix_array







def array_to_ppm_p3():
    pass


def array_to_png(pix_array, img_path):
    img = Image.new('RGB', (len(pix_array), len(pix_array[0])), (255, 255, 255))
    pix_array_img = img.load()
    pix_array_img = pix_array
    img.save(img_path)
