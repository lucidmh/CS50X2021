-- Keep a log of any SQL queries you execute as you solve the mystery.

--TIPS : CRIME HAS HAPPEND IN 2020, 28 JULY, CHAMBERLIN STREET!

--First, i go with the cime scences report to check the year and day and street and also id of the crime because we want to know that which crime is the fiftyville
SELECT
     "description"
FROM
     "crime_scene_reports"
WHERE
     "street" = "Chamberlin Street" AND "day" = "28" AND "year" = "2020"
--the crime has happend in 10:15 in court

--so we realized that now we should check the interviews with that 3 guy
SELECT
     "transcript"
FROM
     "interviews"
WHERE
     "transcript" LIKE "%court%" AND "year" = "2020" AND "month" = "7" AND "day" = "28"
--

--so we realized that interviewer seen that the theft exit from parking lot after ten minutes and suggest that we should check the security log
SELECT
     "license_plate"
FROM
     "courthouse_security_logs"
WHERE
     "year" = "2020" AND "month" = "7" AND "day" = "28" AND "activity" = "exit" AND "hour" = "10" AND "minute" <= "25"
--license plates of suspects = 5P2BI95, 94KL13X, 6P58WS2, 4328GD8, G412CB7, L93JTIZ, 322W7JE, 0NTHK55

--now we should check people license plates
SELECT
     "name"
FROM
     "people"
WHERE
     "license_plate" IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55')
--suspects = Patrick, Amber, Elizabeth, Roger, Danielle, Russell, Evelyn, Ernest

--now we should check the atm logs because one of the interviewer says the ""i see her/him earlier morning in fifer street
SELECT
     "account_number"
FROM
     "atm_transactions"
WHERE
     "year" = "2020" AND "month" = "7" AND "day" = "28" AND "atm_location" LIKE "%Fifer street%" AND "transaction_type" LIKE "withdraw"
--account numbers = 28500762, 28296815, 76054385, 49610011, 16153065, 25506511, 81061156, 26013199

--now we should check the person id's
SELECT
     "person_id"
FROM
     "bank_accounts"
WHERE
     "account_number" IN ('28500762', '28296815', '76054385', '49610011', '16153065', '25506511', '81061156', '26013199')
--person id's = 686048, 514354, 458378, 395717, 396669, 467400, 449774, 438727

--now we should check that this accounts belong to who and than compare them with the parking lot sus
SELECT
     "name"
FROM
     "people"
INNER JOIN
     "bank_accounts" ON people."id" = bank_accounts."person_id"
WHERE
     "person_id" IN ('686048', '514354', '458378', '395717', '396669', '467400', '449774', '438727')
--suspect here = Ernest, Russell, Roy, Bobby, Elizabeth, Danielle, Madison, Victoria
--real suspects are = Russell, Ernest, Elizabeth, Danielle

--now we should check the suspects number
SELECT
     "name", "phone_number", "id"
FROM
     "people"
WHERE
     "name" IN ('Russell', 'Ernest', 'Elizabeth', 'Danielle')
--number = Elizabeth | (829) 555-5269 | id: 396669, Danielle | (389) 555-5198 | id: 467400, Russell | (770) 555-1861 | id: 514354, Ernest | (367) 555-5533 | id: 686048

--now we should check the phone calls because of one of the interviewer
SELECT
     "caller", "receiver"
FROM
     "phone_calls"
WHERE
     "caller" IN ('(829) 555-5269', '(389) 555-5198', '(770) 555-1861', '(367) 555-5533') AND "year" = "2020" AND "month" = "7" AND "day" = "28" AND "duration" <= "60"
--caller | receiver = (Ernest)(367) 555-5533 | (375) 555-8161............(Russell)(770) 555-1861 | (725) 555-3243

--now we should know that who are the receivers
SELECT
     "name", "phone_number", "id"
FROM
     "people"
WHERE
     "phone_number" IN ('(375) 555-8161', '(725) 555-3243')
--receiver = Philip: (725) 555-3243[id: 847116] , Berthold: (375) 555-8161[id: 864400]
--Ernest called Berthold, Russel called Philip (the thief and partner are between them)

--we now that they're(i mean the the partners) gonna runaway from the town tommorow with the first flight and Berthold or Philip will buy the tickets
SELECT
     "id" ,"hour", "minute", "origin_airport_id", "destination_airport_id"
FROM
     "flights"
WHERE
     "year" = "2020" AND "day" = "29" AND "month" = "7"
ORDER BY
     "hour" DESC , "minute"
--tommorow first flight = id | hour | minute | origin_airport_id | destination_airport_id ------> id: 36| hour: 8 | minute: 20 | origin: 8 | destination: 4

--now we should know the person passport number to compare it with this flight passenger
SELECT
     "name", "passport_number"
FROM
     "people"
WHERE
     "id" IN ('514354', '847116', ' 686048', '864400')
ORDER BY
     "name" ASC
--name | passport_number = Berthold | NO passport, Ernest | 5773159633, Philip | 3391710505, Russell | 3592750733

--now we should match the people with the passenger passport
SELECT
     "seat", "passport_number"
FROM
     "passengers"
INNER JOIN
     "flights" ON passengers."flight_id" = flights."id"
WHERE
     "id" = "36" AND "passport_number" IN ('5773159633', '3391710505', '3592750733', ' ')
ORDER BY
     "passport_number" DESC
--4A | 5773159633(ernest passport) and we know that berthold passport number is NULL
--we realized that Ernest and Berthold are this flight passenger, so they are the partner and who stolen the cs50 duck:)

--now we should check that where they'll escape
SELECT
     "full_name", "city"
FROM
     "airports"
INNER JOIN
     "flights" ON airports."id" = flights."destination_airport_id"
WHERE
     "year" = "2020" AND "month" = "7" AND "day" = "29" AND "hour" = "8" AND "minute" = "20" AND "origin_airport_id" = "8"
ORDER BY
     "name" ASC, "city"
--full_name | city = Heathrow Airport | London
--this rich boys gonna leave the fiftyville to london:)





