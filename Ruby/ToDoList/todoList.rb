class Criteria
  attr_accessor :proc

  def initialize(proc)
    @proc = proc
  end

  def self.status(status)
    Criteria.new(Proc.new { |x| x.send(:status) == status })
  end

  def self.priority(priority)
    Criteria.new(Proc.new { |x| x.send(:priority) == priority })
  end

  def self.tags(tags)
    Criteria.new(Proc.new { |x| contains? x.send(:tags), tags })
  end

  def self.contains?(list, sublist)
    (list - sublist).size == list.size - sublist.size
  end

  def &(other)
    Criteria.new(Proc.new { |x| proc.call(x) && other.proc.call(x) })
  end

  def |(other)
    Criteria.new(Proc.new { |x| proc.call(x) || other.proc.call(x) })
  end

  def !
    Criteria.new(Proc.new { |x| !proc.call(x) })
  end
end

class Task
  attr_accessor :status
  attr_accessor :description
  attr_accessor :priority
  attr_accessor :tags

  def initialize(task_props)
    @status = task_props[0].downcase.strip.to_sym
    @description = task_props[1].strip
    @priority = task_props[2].downcase.strip.to_sym
    @tags = task_props[3].strip.split(",").map(&:strip)
  end
end

class TodoList
  include Enumerable

  attr_accessor :tasks

  def initialize(tasks)
    @tasks = tasks
  end

  def self.parse(text)
    @tasks = []
    text.each_line { |line| @tasks << Task.new(line.split("|")) }

    TodoList.new(@tasks)
  end

  def filter(criteria)
    TodoList.new(@tasks.find_all { |task| criteria.proc.call(task) })
  end

  def adjoin(other)
    TodoList.new(@tasks.concat other.tasks)
  end

  def tasks_todo
    @tasks.find_all { |task| task.status == :todo }.size
  end

  def tasks_in_progress
    @tasks.find_all { |task| task.status == :current }.size
  end

  def tasks_completed
    @tasks.find_all { |task| task.status == :done }.size
  end

  def completed?
    @tasks.all? { |task| task.status == :done }
  end

  def each(&block)
    @tasks.each(&block)
  end
end


