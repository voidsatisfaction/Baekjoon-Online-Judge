def find_path(phase, routes)
  $maps[1][1] = 0
  while 1
    next_routes = []
    0.upto(routes.length-1) do |i|
      x = routes[i][0]
      y = routes[i][1]
      if x-1 >= 1 && $maps[x-1][y] == 1
        next_routes.push([x-1,y])
        $maps[x-1][y] = 0
      end
      if x+1 <= N && $maps[x+1][y] == 1
        next_routes.push([x+1,y])
        $maps[x+1][y] = 0
        return phase+1 if x+1 === N && y === M
      end
      if y-1 >= 1 && $maps[x][y-1] == 1
        $maps[x][y-1] = 0
        next_routes.push([x,y-1])
      end
      if y+1 <= M && $maps[x][y+1] == 1
        next_routes.push([x,y+1])
        $maps[x][y+1] = 0
        return phase+1 if x === N && y+1 === M
      end
    end
    phase += 1
    routes = next_routes
  end
end

input = gets.chomp.split(' ').map{ |e| e.to_i }
N = input[0]
M = input[1]
$maps = Array.new(N+1){ Array.new(M+1){0} };
1.upto(N) do |n|
  s = gets.chomp.split('').map{ |e| e.to_i }
  1.upto(M){|m| $maps[n][m] = s[m-1]}
end
p find_path(1,[[1,1]])
