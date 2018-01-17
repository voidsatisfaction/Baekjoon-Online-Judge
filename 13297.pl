chomp (my $N = <STDIN>);
for (my $i=0; $i < $N; $i++) {
  chomp (my $cost = <STDIN>);
  my @cost_digits = split(//, $cost);
  my $estimated = scalar(@cost_digits);
  print "$estimated\n";
}
