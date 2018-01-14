chomp(my $t = <STDIN>);
for(my $i=0; $i < $t; $i++) {
  chomp(my $n = <STDIN>);
  my @all_p_nums = ();
  for(my $j=0; $j < $n; $j++) {
    chomp(my $p_num = <STDIN>);
    push @all_p_nums, $p_num;
  }

  my @sorted_all_p_nums = sort {$a <=> $b} @all_p_nums;

  my %n_index = ();
  my $is_consistent = 1;
  foreach my $p_num (@sorted_all_p_nums) {
    my $temp = '';
    my @p_num_array = split(//, $p_num);
    foreach my $p_digit (@p_num_array) {
      $temp = $temp . $p_digit;
      if ($n_index{$temp}) {
        $is_consistent = 0;
      }
    }
    $n_index{$p_num} = 1;
  }

  if ($is_consistent) {
    print "YES\n";
  } else {
    print "NO\n";
  }
}