-- 코드를 입력하세요
SELECT F.FLAVOR FROM 
ICECREAM_INFO I INNER JOIN FIRST_HALF F ON F.FLAVOR = I.FLAVOR 
WHERE F.TOTAL_ORDER > 3000 AND I.INGREDIENT_TYPE = 'fruit_based'
ORDER BY F.TOTAL_ORDER DESC