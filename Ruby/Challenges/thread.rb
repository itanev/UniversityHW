class Object
  def thread(*operations)
    object = self
    operations.each do |op|
      object = object.send op if op.is_a?(Symbol)
      object = op.call(object) if op.is_a?(Proc)
    end

    object
  end
end
