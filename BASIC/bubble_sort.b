DO
  changed = 0
  FOR I = 1 TO size -1
    IF nums(I) > nums(I + 1) THEN
      tmp = nums(I)
      nums(I) = nums(I + 1)
      nums(I + 1) = tmp
      changed = 1
    END IF
  NEXT
LOOP WHILE(NOT changed)
