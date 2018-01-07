sub get_score {
  my ($str) = @_;
  my @str_array = split(//, $str);
  my $sub = 64;
  my $score = 0;
  foreach my $cp (@str_array) {
    my $alphabet_score = ord($cp) - $sub;
    if ($alphabet_score > 0) {
      $score += $alphabet_score
    }
  }
  return $score;
}

chomp (my $N = <STDIN>);
while ($N--) {
  chomp(my $str = <STDIN>);
  my $score = get_score($str);
  if ($score == 100) {
    print "PERFECT LIFE\n";
  } else {
    print $score, "\n";
  }
}