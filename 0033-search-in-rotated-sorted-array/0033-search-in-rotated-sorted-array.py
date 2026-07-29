class Solution:
    def search(self, nums: List[int], target: int) -> int:
        str_pointer = 0
        end_pointer = len(nums) - 1

        while str_pointer <= end_pointer:
            mid = str_pointer + (end_pointer - str_pointer) // 2

            if nums[mid] == target:
                return mid

            if nums[str_pointer] <= nums[mid]:
                if nums[str_pointer] <= target < nums[mid]:
                    end_pointer = mid - 1
                else:
                    str_pointer = mid + 1

            else:
                if nums[mid] < target <= nums[end_pointer]:
                    str_pointer = mid + 1
                else:
                    end_pointer = mid - 1
        return -1