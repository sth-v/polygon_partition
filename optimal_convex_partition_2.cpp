#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Partition_traits_2.h>
#include <CGAL/partition_2.h>
#include <cassert>
#include <list>
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
void make_polygon(Polygon_2& polygon)
{
    polygon.push_back(Point_2(352, 304 ));
    polygon.push_back(Point_2(326, 235 ));
    polygon.push_back(Point_2(286, 195 ));
    polygon.push_back(Point_2(301, 145 ));
    polygon.push_back(Point_2(290, 89 ));
    polygon.push_back(Point_2(299, 50 ));
    polygon.push_back(Point_2(299, 16 ));
    polygon.push_back(Point_2(352, 14 ));
    polygon.push_back(Point_2(424, 72 ));
    polygon.push_back(Point_2(407, 102 ));
    polygon.push_back(Point_2(400, 187 ));
    polygon.push_back(Point_2(460, 264 ));
    polygon.push_back(Point_2(447, 197 ));
    polygon.push_back(Point_2(479, 186 ));
    polygon.push_back(Point_2(529, 279 ));
    polygon.push_back(Point_2(453, 343 ));
    polygon.push_back(Point_2(396, 493 ));
    polygon.push_back(Point_2(324, 519 ));
    polygon.push_back(Point_2(271, 483 ));
    polygon.push_back(Point_2(313, 402 ));
    polygon.push_back(Point_2(234, 365 ));
    polygon.push_back(Point_2(128, 365 ));
    polygon.push_back(Point_2(120, 318 ));
    polygon.push_back(Point_2(226, 283 ));

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