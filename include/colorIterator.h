#ifndef COLORITERATOR_H
#define COLORITERATOR_H


#include <vector>
#include <iostream>


class colorIterator
{
    public:
        colorIterator(int incrementSize);
        virtual ~colorIterator();

        std::vector<int> incrementColor(int steps);
        std::vector<int> decrementColor(int steps);
        void resetColorSpace();

    protected:

    private:
        std::vector<int> colorSpace;
        int incrementSize;
        int colorSize = 255;
        int maxLim;
        int minLim;
        int minColor;
        bool countUp = true;

        void changeColor(bool countUp, int steps);
        void setIncrementSize(int incrementSize);
        void setColorSize();
        void setColorMaxLim(int maxLim);
        void setColorMinLim(int minLim);
        void setMinColor(int minColor);
        void setCountUp(bool countUp);
};

#endif // COLORITERATOR_H
