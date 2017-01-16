def max?(a,b,c)
  if a > b && a > c
    return a
  elsif b > a && b > c
    return b
  else
    return c
  end
end

def sequal_max(nums)
  max = 0
  sum = 0
  nums.each do |num|
    sum += num
    max = sum if sum > max
  end
  return max
end

def largest?(nums)
  l = nums.length
  if l === 1
    nums[0] 
  elsif l === 2
    max?(nums[0], nums[1], (nums[0]+nums[1]))
  elsif l % 2
    half = l/2-1
    left = nums[0..half].reverse
    right = nums[(half+1)..(l-1)]
    return max?((sequal_max(left) + sequal_max(right)), largest?(left), largest?(right))
  else
    half = l/2
    left = nums[0..(half-1)].reverse
    right = nums[(half+1)..(l-1)]
    return max?((sequal_max(left) + nums[half] + sequal_max(right)), largest?(left), largest?(right))
  end
end

N = gets.chomp.to_i
nums = gets.chomp.split(' ').map{|e| e.to_i }

p largest?(nums)