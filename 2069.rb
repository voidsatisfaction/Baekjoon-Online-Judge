def area(seg)
  (seg[:r] - seg[:l])**2
end

MAX = 33000
n = gets.chomp.to_i
temp = Array.new(MAX){ 0 }
segs = []
n.times do
  l,r = gets.chomp.split(' ').map{ |e| e.to_i }
  temp[l] = r if r > temp[l]
end

temp.each_with_index do |r,l|
  next if r == 0
  temp_seg = {l: l, r: r}
  segs.push(temp_seg)
end

segs.sort!{ |a,b| a[:l] <=> b[:l] }

last_seg = {}
ans = 0

segs.each_with_index do |current_seg, i|
  if i == 0
    ans += area(current_seg)
  else
    ans += area(current_seg)
    if last_seg[:r] > current_seg[:l]
      dup_seg = { l: last_seg[:r], r: current_seg[:l] }
      ans -= area(dup_seg)
    end
  end
  last_seg = current_seg
end

puts ans