/*
A replacement of '*' -> '(' implies +1
A replacement of '*' -> ')' implies -1
At any point, if the count is < 0, drop the path.
Finally, if the count is == 0, accept the path.
As we have three options, the choices can be made in ternary,
Thus, given k choice locations, there are 3 ** k options
Hence, we can reduce the recursion to iteration.
Using a mixture of imp/dec because of readability
*/

def count_options( s ){
  num_stars = sum( s.value ) -> { $.item == _'*' ? 1 : 0  }
  options = set() ; len = #|s|
  map = { _'0' : '',  _'1' : '(' , _'2' : ')' , _'(' : 1, _')' : -1 }
  for ( select_pattern : [0: 3 ** num_stars ] ){
    star_count = -1
    ter_pattern = str( select_pattern , 3 )
    ter_pattern = '0' ** ( #|ter_pattern | - num_stars ) + ter_pattern
    transformed = fold( s.value ,'' ) -> {
      $.prev + ( $.item == _'*' ? map[ter_pattern[ star_count += 1 ]] :  $.item )
    }
    continue( transformed @ options ) // avoid unnecessary stuff
    res = sum ( transformed.value ) -> {
      break( $.prev < 0 ){ -len } ; map[$.item]
    }
    if ( res == 0 ){ options += transformed }
  }
  println( str( options,'\n' ) )
  size( options ) // return size of options
}
println( count_options( '(*(*)*)' ) )