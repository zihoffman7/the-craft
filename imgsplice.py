from PIL import Image

# Load the image
image = Image.open('image.png')  # Replace 'image.png' with your file path

# Image dimensions (64x64)
img_width, img_height = image.size

# Define the size of each region (16x16)
region_size = 16

# Initialize a counter for naming the output images
counter = 0

# Loop through the image and extract each 16x16 region
for row in range(0, img_height, region_size):
    for col in range(0, img_width, region_size):
        # Define the coordinates of the current region
        box = (col, row, col + region_size, row + region_size)
        # Crop the image to get the region
        region = image.crop(box)
        # Save the region as a separate image
        region.save(f'region_{counter}.png')
        counter += 1

print("Image splitting completed.")
