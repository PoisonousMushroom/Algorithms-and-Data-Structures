
<?php
$f = fopen( 'php://stdin', 'r' );
$m=fgets($f);
$n=fgets($f);
fclose($f);
if($n==0){
  echo $m;
} elseif($m==0) {
  echo $n;
} else {
  while(bccomp($m,$n)!=0)
  {
    if(bccomp($m,$n)>0)
    {
      $m=bcsub($m, $n);
    }
    else
    {
      $n=bcsub($n, $m);
    }
  }
  echo $n;
}
?>
