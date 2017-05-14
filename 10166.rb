d1,d2 = gets.chomp.split(' ').map{ |e| e.to_i }
temp = {}
counts = 1

d1.upto(d2) do |d|
  1.upto(d-1) do |i|
    if !temp[[i,d].to_s]
      gcd_i_d = i.gcd(d)
      dd = d / gcd_i_d
      ii = i / gcd_i_d
      j = 1
      while dd*j <= d2
        temp[[j*ii,j*dd].to_s] = true
        j += 1
      end
      counts += 1
    end
  end
end

puts counts