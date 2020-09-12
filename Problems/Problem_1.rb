# Programming language Ruby

# Students will be the collection i.e. Array of Student objects
# Let m = length of students collection array
#     n = size of criteria collection array

def sort(students, criteria)
    return unless students.is_a?(Array) && criteria.is_a?(Array)

    # Covert the criteria to sym so to compare with student property
    students.sort_by{ |student| criteria.map(&:to_sym) }
end

# Time Complexity
# 1. To convert criteria i.e. array of strings to array of symbols O(n)
# 2. To sort the students record via sort_by method O(mlogm)
# Overall Time Complexity = O(n) + O(mlogm)

# Space Complexity
# 1. To use map return a array of symbols O(n)
# Overall Space complexity = O(n)
