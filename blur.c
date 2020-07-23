// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
        int i, j, k, l, r, g, b, pixcount;
        RGBTRIPLE tmp[height][width];
        
    for (i = 0; i < height; i++)//runs over each pixel in img
    {
        for (j = 0; j < width; j++)//
        {
            pixcount = 0;
            r = 0;
            g = 0;
            b = 0;
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)//for each pixel this loop runs 9 times, once for each pixel in a 3x3 grid centered on said pixel
                {
                    if ( (0 <= i + k && i + k < width - 1) && (0 <= j + l && j + l < height - 1) ) //dont run if out of bounds of img
                    {
                        r += image[i + k][j + l].rgbtRed; //running totals for total RGB in 3x3 space
                        g += image[i + k][j + l].rgbtGreen;//
                        b += image[i + k][j + l].rgbtBlue;//
                        pixcount++; //running total of number of pixels in 3x3 space
                    }
                }
            }
            tmp[i][j].rgbtRed = (round((float)r / (float)pixcount )); //find average RGB in 3x3 space and send to tmp array
            tmp[i][j].rgbtGreen = (round((float)g / (float)pixcount ));//
            tmp[i][j].rgbtBlue = (round((float)b / (float)pixcount ));//
        }
        
    }
    
    for (i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            image[i][j] = tmp[i][j];//copy back to original img
        }
        
    }
    return;
}
