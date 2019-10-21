#include <vector>
#include <tuple>

template < size_t I, class T >
struct LineReader {
    bool read(std::ifstream& inFile, T& line){
        LineReader< I - 1, T > lineReader;

        if (!lineReader.read(inFile, line))
            return false;

        if (!( inFile >> std::get< I >(line) ) )
            return false;

        return true;
    }
};

template < class T >
struct LineReader< 0, T > {
    bool read(std::ifstream& inFile, T& line){
        if (!(inFile >> std::get< 0 >(line)))
            return false;
        return true;
    }
};


template < class... Types >
class ReaderTXT {
    public:
    std::vector< std::tuple<Types ... > > readTXT(const std::string& filename);
};

template <class... Types > 
std::vector< std::tuple<Types ... > > ReaderTXT< Types ... >::readTXT(const std::string& filename){

    std::ifstream inFile;
    inFile.open(filename);

    std::vector< std::tuple< Types ... > > data;
    std::tuple< Types ... > line;

    LineReader< sizeof ... (Types) - 1, std::tuple< Types ... > > lineReader;
    while (lineReader.read(inFile, line))
        data.push_back(line);

    inFile.close();
        
    return data;
}


