#ifndef COLORITERATOR_H
#define COLORITERATOR_H


#include <vector>
#include <iostream>


class colorIterator
{
    public:
        colorIterator(int incrementSize); //int r, int g, int b, int incrementSize);
        virtual ~colorIterator();

        std::vector<int> incrementColor(int steps);
        std::vector<int> decrementColor(int steps);
        void resetColorSpace();

    protected:

    private:
        std::vector<int> colorSpace;
        int incrementSize;
        int colorSize = 255;
        bool countUp = true;

        void changeColor(bool countUp, int steps);

};

#endif // COLORITERATOR_H
