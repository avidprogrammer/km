object listrev {
  def f(arr: List[Int]): List[Int] = arr match {
    case Nil => List()
    case a :: Nil => List(a)
    case a :: b => f(b):+a
  }                                               //> f: (arr: List[Int])List[Int]
  
  def fabs(arr:List[Int]):List[Int] = arr.map(ele => if (ele < 1) ele * -1 else ele)
                                                  //> fabs: (arr: List[Int])List[Int]
  
  fabs(List(-1,2,-3))                             //> res0: List[Int] = List(1, 2, 3)
  f(List(1,2,3))                                  //> res1: List[Int] = List(3, 2, 1)
}