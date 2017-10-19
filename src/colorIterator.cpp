#include "colorIterator.h"



std::vector<int> colorSpace;
int incrementSize;
int colorSize = 255;
int maxLim = colorSize - incrementSize +1;
int minLim = 0 + incrementSize +1 +50;
int minColor = 50;
bool countUp = false;



/// Extra set methods.
void colorIterator::setIncrementSize(int incrementSize)
{
    this->incrementSize = incrementSize;
}
void colorIterator::setColorSize()
{
    this->colorSize = colorSize;
}
void colorIterator::setColorMaxLim(int maxLim)
{
    this->maxLim = maxLim;
}
void colorIterator::setColorMinLim(int minLim)
{
    this->minLim = minLim;
}
void colorIterator::setMinColor(int minColor)
{
    this->minColor = minColor;
}
void colorIterator::setCountUp(bool countUp)
{
    this->countUp = true;
}



colorIterator::colorIterator(int incrementSize)
{
    this->incrementSize = incrementSize;

    colorSpace.push_back(0);
    colorSpace.push_back(0);
    colorSpace.push_back(150);
}

colorIterator::~colorIterator()
{
    //dtor
}



void colorIterator::resetColorSpace()
{
    colorSpace.at(0) = 150;
    colorSpace.at(1) = 150;
    colorSpace.at(2) = 150;
}

void colorIterator::changeColor(bool countUp, int steps)
{
    steps = steps%(colorSize*colorSpace.size());
    for(int i = 0; i < steps; i++)
    {
        if(countUp)
        {
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
