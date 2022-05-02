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
    polygon.push_back(Point_2(134, 101));
    polygon.push_back(Point_2(141, 89));
    polygon.push_back(Point_2(148, 77));
    polygon.push_back(Point_2(155, 65));
    polygon.push_back(Point_2(161, 55));
    polygon.push_back(Point_2(164, 55));
    polygon.push_back(Point_2(177, 53));
    polygon.push_back(Point_2(190, 51));
    polygon.push_back(Point_2(191, 52));
    polygon.push_back(Point_2(200, 62));
    polygon.push_back(Point_2(209, 72));
    polygon.push_back(Point_2(219, 83));
    polygon.push_back(Point_2(225, 90));
    polygon.push_back(Point_2(224, 93));
    polygon.push_back(Point_2(217, 105));
    polygon.push_back(Point_2(210, 117));
    polygon.push_back(Point_2(203, 129));
    polygon.push_back(Point_2(196, 141));
    polygon.push_back(Point_2(189, 153));
    polygon.push_back(Point_2(189, 153));
    polygon.push_back(Point_2(185, 166));
    polygon.push_back(Point_2(180, 180));
    polygon.push_back(Point_2(176, 193));
    polygon.push_back(Point_2(172, 206));
    polygon.push_back(Point_2(168, 219));
    polygon.push_back(Point_2(167, 221));
    polygon.push_back(Point_2(166, 233));
    polygon.push_back(Point_2(166, 247));
    polygon.push_back(Point_2(165, 261));
    polygon.push_back(Point_2(165, 275));
    polygon.push_back(Point_2(164, 283));
    polygon.push_back(Point_2(166, 288));
    polygon.push_back(Point_2(170, 301));
    polygon.push_back(Point_2(174, 315));
    polygon.push_back(Point_2(178, 328));
    polygon.push_back(Point_2(181, 337));
    polygon.push_back(Point_2(183, 341));
    polygon.push_back(Point_2(191, 353));
    polygon.push_back(Point_2(198, 365));
    polygon.push_back(Point_2(205, 377));
    polygon.push_back(Point_2(212, 388));
    polygon.push_back(Point_2(216, 395));
    polygon.push_back(Point_2(212, 400));
    polygon.push_back(Point_2(203, 411));
    polygon.push_back(Point_2(199, 417));
    polygon.push_back(Point_2(193, 419));
    polygon.push_back(Point_2(179, 423));
    polygon.push_back(Point_2(166, 428));
    polygon.push_back(Point_2(160, 430));
    polygon.push_back(Point_2(156, 424));
    polygon.push_back(Point_2(148, 412));
    polygon.push_back(Point_2(140, 401));
    polygon.push_back(Point_2(132, 389));
    polygon.push_back(Point_2(124, 378));
    polygon.push_back(Point_2(119, 370));
    polygon.push_back(Point_2(117, 366));
    polygon.push_back(Point_2(112, 353));
    polygon.push_back(Point_2(108, 340));
    polygon.push_back(Point_2(103, 327));
    polygon.push_back(Point_2(98, 314));
    polygon.push_back(Point_2(93, 301));
    polygon.push_back(Point_2(91, 296));
    polygon.push_back(Point_2(91, 288));
    polygon.push_back(Point_2(91, 274));
    polygon.push_back(Point_2(91, 260));
    polygon.push_back(Point_2(91, 246));
    polygon.push_back(Point_2(91, 232));
    polygon.push_back(Point_2(91, 230));
    polygon.push_back(Point_2(94, 219));
    polygon.push_back(Point_2(97, 205));
    polygon.push_back(Point_2(101, 192));
    polygon.push_back(Point_2(104, 178));
    polygon.push_back(Point_2(108, 165));
    polygon.push_back(Point_2(113, 152));
    polygon.push_back(Point_2(118, 139));
    polygon.push_back(Point_2(123, 126));
    polygon.push_back(Point_2(128, 114));


}


int main()
{
   Polygon_2    polygon;
   Polygon_list partition_polys;

   make_polygon(polygon);
   CGAL::greene_approx_convex_partition_2(polygon.vertices_begin(),
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
