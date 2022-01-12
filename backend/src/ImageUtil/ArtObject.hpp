#ifndef ARTOBJ_H
#define ARTOBJ_H

#include <string>
#include <vector>
#include <unordered_map>

#include "ImageUtil/Image.hpp"
#include "ImageUtil/ImageWriter/ImageWriter.hpp"
#include "ImageUtil/ImageWriter/LibTiffWriter.hpp"


namespace btrgb {

    class ArtObject {

    private:
        std::unordered_map<std::string, image*> images;
        ImageWriter* tiffWriter;

    public:
        ArtObject();
        ~ArtObject();

        void newImage(std::string name, std::string filename);

        void setImage(std::string name, image* im);
        image* getImage(std::string name);
        bool imageExists(std::string name);

        /* To do, add parameter for photometric tiff tag: RGB, or grayscale. */
        void outputImageAsTIFF(std::string name);

        /* Iterators over all image entries. */
        std::unordered_map<std::string, image*>::iterator begin() noexcept {return images.begin();};
        std::unordered_map<std::string, image*>::iterator end() noexcept {return images.end();};
    };




    class ArtObjectError : public std::exception {};
    
    class ArtObj_ImageAlreadyExists : public ArtObjectError {
        public:
        virtual char const * what() const noexcept { return "ArtObject Error: An image with that name already exists."; }
    };

    class ArtObj_ImageDoesNotExist : public ArtObjectError {
        public:
        virtual char const * what() const noexcept { return "ArtObject Error: That image does not exist."; }
    };

    class ArtObj_FailedToWriteImage : public ArtObjectError {
        public:
        virtual char const * what() const noexcept { return "ArtObject Error: Failed to write image."; }
    };

}



#endif
