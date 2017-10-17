#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H


#include "colorIterator.h"

#include <string>
#include <fstream>
#include <vector>
#include <iostream>


class imageHandler
{
    public:
        imageHandler(std::vector<std::vector<int> > &iterPlane, std::string filePath, std::string magicNumber, int width, int height, int colorRange);
        virtual ~imageHandler();
        void    makeImgFile();

    protected:

    private:
        std::string                     filePath;
        std::string                     magicNumber;
        int                             width;
        int                             height;
        int                             colorRange;
        std::vector<std::vector<int> >  m_iterPlane;
        std::vector<int>                ppmVector;

        std::vector<int>    vect2ToVect(std::vector<std::vector<int> > plane);
};

#endif // IMAGEHANDLER_H
