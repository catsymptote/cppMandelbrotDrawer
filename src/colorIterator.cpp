#include "colorIterator.h"




std::vector<int> colorSpace;
int incrementSize;
int colorSize = 255;
int maxLim = colorSize - incrementSize +1;
int minLim = 0 + incrementSize +1 +50;
int minColor = 50;
bool countUp = true;




colorIterator::colorIterator(int incrementSize) //int r, int g, int b, int incrementSize=1)
{
    //colorSpace[0] = r;
    //colorSpace[1] = g;
    //colorSpace[2] = b;
    this->incrementSize = incrementSize;
    colorSpace.push_back(0);
    colorSpace.push_back(0);
    colorSpace.push_back(150);

    /* Color space validity checker.
    if(
       colorSpace[0] > colorSize
    )
    {
       colorSpace[0] = colorSize;
    }*/
}

colorIterator::~colorIterator()
{
    //dtor
}





void colorIterator::resetColorSpace()
{
    colorSpace.at(0) = 0;
    colorSpace.at(1) = 0;
    colorSpace.at(2) = 150;
}

void colorIterator::changeColor(bool countUp, int steps)
{
    //std::cout << "colorIterator. countUp:steps - " << countUp << ":" << steps << std::endl;
    steps = steps%(colorSize*colorSpace.size());
    for(int i = 0; i < steps; i++)
    {

        //if(colorSpace[2] < 255)
        //{
        //    colorSpace[0] += incrementSize;
        //}


        if(countUp)
        {

            //std::cout << "Hi there1" << std::endl;
            //std::cout << "colorSize - incrementSize +1: \t" << colorSize - incrementSize +1 << std::endl;
            //std::cout << "colorSize \t" << colorSize << std::endl;
            //std::cout << "incrementSize \t" << incrementSize << std::endl;
            //std::cout << colorSpace.size() << std::endl;
            //std::cout << colorSpace.at(0) << std::endl;
            //std::cout << colorSpace.at(1) << std::endl;
            //std::cout << colorSpace.at(2) << std::endl;


            /// Blue not max. Blue++
            if(colorSpace[2] < maxLim)
            {
                colorSpace[2] += incrementSize;
            }
            /// Green not max, blue max. Green++
            else if(colorSpace[1] < maxLim && colorSpace[2] >= maxLim)
            {
                colorSpace[2] = colorSize;
                colorSpace[1] += incrementSize;
            }
            /// Red not max, blue, green max. Red++
            else if(colorSpace[0] < maxLim && colorSpace[1] >= maxLim && colorSpace[2] >= maxLim)
            {
                colorSpace[1] = colorSize;
                colorSpace[0] += incrementSize;
            }
            /// Red, green, blue max. Reset direction.
            else if(colorSpace[0] >= maxLim && colorSpace[1] >= maxLim && colorSpace[2] >= maxLim)
            {
                colorSpace[0] = colorSize;
                countUp = !countUp;
            }
            //std::cout << "Hi there6" << std::endl;
        }
        else
        {
            /// Blue not 0. Blue--
            if(colorSpace[2] > minLim)
            {
                colorSpace[2] -= incrementSize;
            }
            /// Green not 0, blue 0. Green--
            else if(colorSpace[1] > minLim && colorSpace[2] <= minLim)
            {
                colorSpace[2] = minColor;
                colorSpace[1] -= incrementSize;
            }
            /// Red not 0, blue, green 0. Red--
            else if(colorSpace[0] > minLim && colorSpace[1] <= minLim && colorSpace[2] <= minLim)
            {
                colorSpace[1] = minColor;
                colorSpace[0] -= incrementSize;
            }
            /// Red, green, blue 0. Reset direction.
            else if(colorSpace[0] <= minLim && colorSpace[1] <= minLim && colorSpace[2] <= minLim)
            {
                colorSpace[0] = minColor;
                countUp = !countUp;
            }
        }

    }
}


std::vector<int> colorIterator::incrementColor(int steps)
{
    changeColor(countUp, steps);
    return colorSpace;
}

std::vector<int> colorIterator::decrementColor(int steps)
{
    changeColor(!countUp, steps);
    return colorSpace;
}
