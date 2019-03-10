#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    //Leitura da imagem
    Mat image = imread("test.jpg", IMREAD_COLOR);

    //Contagem de Tempo
    clock_t tStart = clock();

    //Aplicando Filtro Negativo
    for (int x = 0; x < image.cols; x++)
	{
		for (int y = 0; y < image.rows; y++)
		{
            	image.at<Vec3b>(y, x)[0] = 255 - image.at<Vec3b>(y, x)[0];
        	}
	}

	for (int x = 0; x < image.cols; x++)
	{
		for (int y = 0; y < image.rows; y++)
		{
            	image.at<Vec3b>(y, x)[1] = 255 - image.at<Vec3b>(y, x)[1];
        	}
	}

	for (int x = 0; x < image.cols; x++)
	{
		for (int y = 0; y < image.rows; y++)
		{
            	image.at<Vec3b>(y, x)[2] = 255 - image.at<Vec3b>(y, x)[2];
        	}
	}

    //Apresenta a Contagem de Tempo
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    //Apresenta a Imagem
    namedWindow("Display window", WINDOW_NORMAL);
    imshow("Display window", image);
    waitKey();

    return 0;
}
