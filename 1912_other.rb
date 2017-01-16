N = gets.chomp.to_i
nums = gets.chomp.split(' ').map{|e| e.to_i }

def largest?(nums)
  start = false
  0.upto(nums.length-1) do |i|
    if nums[i] > 0
      start = i 
      break
    end
  end
  return [nums].max if !start
  sequal_sum = nums[start]
  max = nums[start]
  (start+1).upto(nums.length-1) do |i|
    sequal_sum += nums[i]
    if nums[i] < 0 && sequal_sum >= 0
      next
    elsif sequal_sum < 0
      sequal_sum = 0
    elsif nums[i] >= 0 && sequal_sum >= max
      max = sequal_sum
    else
      next
    end
  end
  return max
end

p largest?(nums)