#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Partition_traits_2.h>
#include <CGAL/partition_2.h>
#include <cassert>
#include <list>
#include <json/json.h>
typedef Json::Reader Json_reader;
typedef Json::Value Json_root;

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Partition_traits_2<K>                         Partition_traits_2;
typedef Partition_traits_2::Polygon_2                                   Polygon_2;
typedef Partition_traits_2::Point_2                                     Point_2;
typedef std::list<Polygon_2>                                Polygon_list;

/*
      v4     v2
      | \   /|
      |  \ / |
      |  v3  |typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Partition_traits_2<K>                         Traits;
typedef Traits::Polygon_2                                   Polygon_2;
typedef Traits::Point_2                                     Point_2;
typedef std::list<Polygon_2>                                Polygon_list;

      |      |
      v0-----v1
 */

int point_array[][2] = {
        {352, 30},
        {326, 23},
        {286, 19},
        {301, 14},
        {290, 89},
        {299, 50},
        {299, 16},
        {352, 14},
        {424, 72},
        {407, 10},
        {400, 18},
        {460, 26},
        {447, 19},
        {479, 18},
        {529, 27},
        {453, 34},
        {396, 49},
        {324, 51},
        {271, 48},
        {313, 40},
        {234, 36},
        {128, 36},
        {120, 31}
};

void make_polygon(Polygon_2& polygon)
{
    polygon.push_back(Point_2(538, 736));
    polygon.push_back(Point_2(656, 877));
    polygon.push_back(Point_2(951, 819));
    polygon.push_back(Point_2(1780, 594));
    polygon.push_back(Point_2(1858, 576));
    polygon.push_back(Point_2(2708, 362));
    polygon.push_back(Point_2(2917, 667));
    polygon.push_back(Point_2(1987, 887));
    polygon.push_back(Point_2(2263, 1261));
    polygon.push_back(Point_2(1271, 1510));
    polygon.push_back(Point_2(1198, 1474));
    polygon.push_back(Point_2(1044, 1496));
    polygon.push_back(Point_2(842, 1261));
    polygon.push_back(Point_2(479, 1013));
    polygon.push_back(Point_2(213, 821));


}

int main( )
{
    std::vector<K::Point_2> points;

    Polygon_2 polygon;

    Polygon_list partition_polys;


    make_polygon(polygon);
    CGAL::optimal_convex_partition_2(polygon.vertices_begin(),
                                     polygon.vertices_end(),
                                     std::back_inserter(partition_polys));
    for (const Polygon_2& poly : partition_polys){
        for(Point_2 p : poly.container()){
            std::cout  << p << ", ";
        }
        std::cout << std::endl;

    }
    assert(CGAL::partition_is_valid_2(polygon.vertices_begin(),
                                      polygon.vertices_end(),
                                      partition_polys.begin(),
                                      partition_polys.end()));
    return 0;
}