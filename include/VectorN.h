#include <vector>

namespace MML
{
    class VectorN
    {
        public:
            VectorN(int n) : _elems(n) {}

            double& operator[](int n) { return _elems[n]; }
            
        private:
            std::vector<double> _elems;
    };
}