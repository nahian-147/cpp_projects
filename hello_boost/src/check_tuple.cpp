#include <stdio.h>
#include <boost/tuple/tuple.hpp>

int main(){
    boost::tuple<int, int, int> t;
    t = boost::make_tuple(4, 5, 6);
    printf("%d\n", boost::get<0>(t));
    printf("%d\n", boost::get<1>(t));
    printf("%d\n", boost::get<2>(t));
    return 0;
}
