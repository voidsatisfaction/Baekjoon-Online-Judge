n = gets.chomp.to_i
m = gets.chomp.to_i
graph = Array.new(n+1){ Array.new }
m.times do
  a,b = gets.chomp.split(' ').map{ |e| e.to_i }
  graph[a].push(b)
  graph[b].push(a)
end

counts = 0
counted = Array.new(n+1){ false }
counted[1] = true

graph[1].each do |f|
  if !counted[f]
    counts += 1
    counted[f] = true
  end
  graph[f].each do |ff|
    if !counted[ff]
      counts += 1
      counted[ff] = true
    end    
  end
end

puts counts