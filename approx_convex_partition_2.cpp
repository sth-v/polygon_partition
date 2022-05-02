#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Partition_traits_2.h>
#include <CGAL/partition_2.h>
#include <cassert>
#include <list>


typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Partition_traits_2<K>                         Traits;
typedef Traits::Point_2                                     Point_2;
typedef Traits::Polygon_2                                   Polygon_2;
typedef std::list<Polygon_2>                                Polygon_list;

void make_polygon(Polygon_2& polygon)
{
    polygon.push_back(Point_2(34, 103));
    polygon.push_back(Point_2(52, 80));
    polygon.push_back(Point_2(105, 85));
    polygon.push_back(Point_2(121, 155));
    polygon.push_back(Point_2(152, 220));
    polygon.push_back(Point_2(192, 267));
    polygon.push_back(Point_2(241, 295));
    polygon.push_back(Point_2(306, 314));
    polygon.push_back(Point_2(309, 341));
    polygon.push_back(Point_2(289, 377));
    polygon.push_back(Point_2(219, 362));
    polygon.push_back(Point_2(147, 327));
    polygon.push_back(Point_2(102, 278));
    polygon.push_back(Point_2(70, 220));
    polygon.push_back(Point_2(45, 155));




}


int main()
{
   Polygon_2    polygon;
   Polygon_list partition_polys;

   make_polygon(polygon);

   CGAL::approx_convex_partition_2(polygon.vertices_begin(),
                                   polygon.vertices_end(),
                                   std::back_inserter(partition_polys));
   for (const Polygon_2& poly : partition_polys){
       for (Point_2 p: poly.container()) {
           std::cout << p << ", ";
       }
       std::cout << std::endl;
   }

    assert(CGAL::convex_partition_is_valid_2(polygon.vertices_begin(),
                                            polygon.vertices_end(),
                                            partition_polys.begin(),
                                            partition_polys.end()));
   return 0;
}
