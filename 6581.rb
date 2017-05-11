require 'io/console'

HR = '-' * 80

contents = []
line = ''

while (line = $stdin.gets)
  contents.push(line.chomp.split(' ').compact)
end

contents.delete_if{ |e| e == [] }

# File.open('6581_sample.txt') do |file|
#   file.each_line do |line|
#     contents.push(line.chomp.split(' '))
#   end
# end

contents.flatten.each do |word|
  case word
  when '<br>'
    if line == ''
      print "\n"
    else
      puts line
      line = ''
    end
  when '<hr>'
    if line == ''
      puts HR
    else
      puts line
      puts HR
      line = ''
    end
  else
    if line.length == 0
      line += word
    else
      if line.length + word.length + 1 >= 80
        puts line
        line = word
      else
        line = line + ' ' + word
      end
    end
  end
end

puts line if line != ''