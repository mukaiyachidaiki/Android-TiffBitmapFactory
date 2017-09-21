//
// Created by beyka on 9/20/17.
//

#ifndef TIFFSAMPLE_BMPTOTIFFCONVERTER_H
#define TIFFSAMPLE_BMPTOTIFFCONVERTER_H

#include <stdlib.h>
#include <stdio.h>
#include <tiffio.h>
#include "fcntl.h"
#include "unistd.h"
#include <jpeglib.h>
#include <setjmp.h>
#include "BaseTiffConverter.h"
#include "BMP.h"

#define LOGI(x) __android_log_print(ANDROID_LOG_DEBUG, "BmpToTiffConverter", "%s", x)
#define LOGII(x, y) __android_log_print(ANDROID_LOG_DEBUG, "BmpToTiffConverter", "%s %d", x, y)
#define LOGIF(x, y) __android_log_print(ANDROID_LOG_DEBUG, "BmpToTiffConverter", "%s %f", x, y)
#define LOGIS(x, y) __android_log_print(ANDROID_LOG_DEBUG, "BmpToTiffConverter", "%s %s", x, y)

#define LOGE(x) __android_log_print(ANDROID_LOG_ERROR, "BmpToTiffConverter", "%s", x)
#define LOGES(x, y) __android_log_print(ANDROID_LOG_ERROR, "BmpToTiffConverter", "%s %s", x, y)
#define LOGEI(x, y) __android_log_print(ANDROID_LOG_ERROR, "BmpToTiffConverter", "%s %d", x, y)

class BmpToTiffConverter : public BaseTiffConverter
{
    public:
        explicit BmpToTiffConverter(JNIEnv *, jclass, jstring, jstring, jobject, jobject);
        ~BmpToTiffConverter();
        virtual jboolean convert();

    private:
        TIFF *tiffImage;
        FILE *inFile;

        /*
        int componentsPerPixel;

        char jpeg_struct_init;
        struct jpeg_decompress_struct cinfo;
        struct jpeg_error_mgr jerr;
        */

        unsigned char  * getPixelsFromBmp(int*, int*);

        //METHODDEF(void) JpgToTiffConverter::my_error_exit (j_common_ptr)
        unsigned char * convertArgbToBilevel(unsigned char *, int, uint32, uint32);

};

#endif //TIFFSAMPLE_BMPTOTIFFCONVERTER_H
