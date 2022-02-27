#if !defined  __MML_VECTORN_H
#define __MML_VECTORN_H

#include <vector>

namespace MML
{
    class VectorN
    {
        public:
            VectorN(int n) : _elems(n) {}
            VectorN(std::initializer_list<double> list) : _elems(list) { }

            double& operator[](int n) { return _elems[n]; }
            
        private:
            std::vector<double> _elems;
    };
}

#endif