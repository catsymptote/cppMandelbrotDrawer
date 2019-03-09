namespace cmd
{
    std::string tmpDir      = "imgTmp\\";
    std::string outputDir   = "img\\";
    std::string inputFExt   = ".ppm";
    std::string outputFExt  = ".png";


    std::string execCmd(const char* cmd)
    {
        std::cout << "::\t" << cmd << std::endl;
        std::array<char, 128> buffer;
        std::string result;
        std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
        if (!pipe) throw std::runtime_error("popen() failed!");
        while (!feof(pipe.get())) {
            if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
                result += buffer.data();
        }
        return result;
    }


    void del(const char* fname) //std::string fname)
    {
        std::string delCmd = "del \"" + tmpDir + fname + inputFExt + "\"";
        char *delChr = &delCmd[0];
        std::cout << execCmd(delChr) << std::endl;
    }


    void mov(const char* fname)
    {
        std::string mvCmd = "mv " + tmpDir + fname + outputFExt + " " + outputDir + fname + outputFExt;
        char *mvChr = &mvCmd[0];
        std::cout << execCmd(mvChr) << std::endl;
    }


    void open(const char* fname)
    {
        return; // Comment out to open image.
        std::string startCmd = "start " + outputDir + fname + outputFExt;
        char *startChr = &startCmd[0];
        std::cout << execCmd(startChr) << std::endl;
    }
}
