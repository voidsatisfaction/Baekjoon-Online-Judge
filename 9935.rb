s = STDIN.gets.chomp
e = STDIN.gets.chomp
ans = []

0.upto(s.length-1) do |i|
  a = s[i]
  ans.push(a)
  if ans.length < e.length
    next
  else
    if (ans[(ans.length-1)-(e.length-1)] === e[0]) && (ans[(ans.length-e.length)..(ans.length-1)].join('') === e)
      (e.length).times do
        ans.pop
      end 
    end
  end
end

if ans.join('').empty?
  p "FRULA"
else
  p ans.join('')
end