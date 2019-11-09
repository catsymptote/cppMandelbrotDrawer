#ifndef IMAGECONSTRUCTOR_H
#define IMAGECONSTRUCTOR_H


class ImageConstructor
{
    public:
        ImageConstructor();
        virtual ~ImageConstructor();
        void run();
        void setMode(bool);

    protected:

    private:
        bool buddah = false;
};

#endif // IMAGECONSTRUCTOR_H
