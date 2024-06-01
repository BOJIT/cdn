import glob
from PIL import Image

MAX_WIDTH = 1200
MAX_HEIGHT = 1200

files = glob.glob("./staging/*.JPG") + glob.glob("./staging/*.PNG")

for f in files:
    print(f)
    img = Image.open(f)
    if img.width > MAX_WIDTH or img.height > MAX_HEIGHT:
        img.thumbnail([MAX_WIDTH, MAX_HEIGHT])
        img.save(f)
