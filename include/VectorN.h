#if !defined  __MML_VECTORN_H
#define __MML_VECTORN_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <initializer_list>

namespace MML
{
    class VectorN
    {
        public:
            VectorN(int n) : _elems(n) {}
            VectorN(std::initializer_list<double> list) : _elems(list) { }

            double& operator[](int n) { return _elems[n]; }
            
            size_t size() const { return _elems.size(); }

            std::string to_string(std::string format)
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
                    else
                        first = false;

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