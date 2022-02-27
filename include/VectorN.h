#if !defined  __MML_VECTORN_H
#define __MML_VECTORN_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
namespace MML
{
    class VectorN
    {
        public:
            VectorN(int n) : _elems(n) {}
            VectorN(std::initializer_list<double> list) : _elems(list) { }

            double& operator[](int n) { return _elems[n]; }
            
            std::string to_string()
            {
                std::string a{"0.0"};

                return a;
            }
            friend std::ostream& operator<<(std::ostream& stream, const VectorN &a)
            {
                stream << "[";
                bool first = true;
                for(const double& x : a._elems)
                {
                    if( !first )
                        stream << ", ";
                    stream << std::setw(8) << x;
                }
                stream << "]";

                return stream;
            }
        private:
            std::vector<double> _elems;
    };
}

#endif