CREATE DATABASE Ford_Mexico
USE Ford_Mexico

CREATE TABLE Automovil
(
ID_auto varchar(20) PRIMARY KEY,
Marca varchar(40),
Submarca varchar(40),
Año smallint,
Pais_Origen varchar(40),
Estatus varchar (10),
Precio decimal(8,2),
ID_Persona varchar(10)
)
--LLave Foranea
ALTER TABLE Automovil
ADD CONSTRAINT FK_Automovil_Persona
FOREIGN KEY (ID_Persona)
REFERENCES Persona(ID_Persona)

--Introduccion de Datos
INSERT INTO Automovil(ID_Auto, Marca, Submarca, Año, Pais_Origen, Estatus, Precio, ID_Persona)
VALUES
('A-1233', 'Ford', 'Fusion', 2014, 'México', 'Vendido', 200000.00, '1500-1'),
('A-199', 'Nissan', 'Platina', 2000, 'E.U.A', 'Apartado', 45000.00, '1100-0'),
('A-20987', 'Nissan', 'Altima', 2010, 'Japón', 'Vendido', 100000.00, '1100-0'),
('A-54', 'Nissan', 'Altima', 2016, 'Japón', 'Vendido', 165000.00, '1600-0'),
('A-788', 'VW', 'Jetta', 2017, 'Brasil', 'Apartado', 350000.00, '1300-5'),
('A-90889', 'Chevrolet', 'Camaro', 2017, 'E.U.A.', 'Vendido', 490000.00, '1300-5')

CREATE TABLE Persona
(
ID_Persona varchar(10) PRIMARY KEY,
Nombre_Persona varchar(60),
Municipio_Vive varchar(40),
Edad tinyint, 
Estado_Nacimiento tinyint --FOREIGN KEY REFERENCES Estado_Nacimiento(ID_Estado)
)
--Llave Foranea
ALTER TABLE Persona
ADD CONSTRAINT FK_Persona_Estado
FOREIGN KEY (Estado_Nacimiento)
REFERENCES Estado_Nacimiento(ID_Estado)

--Introduccion de Datos
INSERT INTO Persona(ID_Persona, Nombre_Persona, Municipio_Vive, Edad, Estado_Nacimiento)
VALUES
('1100-0', 'José Aguilar Núñez', 'Ecatepec', 32, 1),
('1200-9', 'Geman Lopez Cruz', 'Tlalnepantla', 45, 1),
('1300-5', 'Alfredo Vargas Lira', 'Tlalnepantla', 19, 3),
('1400-0', 'María Luisa Gil Cruz', 'Naucalpan', 22, 2),
('1500-1', 'Armando Vargas Razo', 'Tlalnepantla', 45, 2),
('1600-0', 'Roberto Yunes Corro', 'Cuautitlán', 30, 4)

CREATE TABLE Autobus
(
ID_bus varchar(10) PRIMARY KEY,
Marca varchar(40),
Submarca varchar(40),
Año smallint,
Pais_Origen varchar(40),
Estatus varchar(10),
Precio decimal(8,2),
ID_Persona varchar(10)
)
--Llave Foranea
ALTER TABLE Autobus
ADD CONSTRAINT FK_bus_Persona
FOREIGN KEY (ID_Persona)
REFERENCES Persona(ID_Persona)

--Introduccion de Datos
INSERT INTO Autobus(ID_bus, Marca, Submarca, Año, Pais_Origen, Estatus, Precio, ID_Persona)
VALUES
('AU-199', 'Kenworth', 'Harvester', 2000, 'E.U.A', 'Vendido', 45000.00, '1200-9'),
('AU-20987', 'Kenworth', 'Dina', 2010, 'Mexico', 'Vendido', 100000.00, '1200-9'),
('AU-54', 'Kenworth', 'Hino', 2016, 'Brazil', 'Vendido', 165000.00, '1500-1'),
('AU-788', 'International', 'Charge', 2017, 'Brasil', 'Apartado', 350000.00, '1300-5'),
('AU-90889', 'Chevrolet', 'Camaro', 2017, 'E.U.A.', 'Vendido', 490000.00, '1600-0')


CREATE TABLE Estado_Nacimiento
(
ID_Estado tinyint PRIMARY KEY,
Descripcion varchar(40)
)

--Introduccion de Datos
INSERT INTO Estado_Nacimiento
VALUES
(1, 'Querétaro'),
(2, 'Estado de Mexico'),
(3, 'Puebla'),
(4, 'Sonora'),
(5, 'Veracruz'),
(6, 'Michoacan')

--CONSULTAS DE LA PRACTICA
--Consulta A)
SELECT * FROM Persona
--Consulta B
SELECT P.Nombre_Persona, A.Submarca, A.Marca, E.Descripcion AS Estado_Nacimiento
FROM Persona P
INNER JOIN Automovil A ON P.ID_Persona = A.ID_Persona
INNER JOIN Estado_Nacimiento E ON P.Estado_Nacimiento = E.ID_Estado
WHERE P.Nombre_Persona = 'Alfredo Vargas Lira'
--Consulta C)
SELECT ID_bus, Marca, Submarca, Año, Pais_Origen, Estatus, ID_Persona, Precio, 
Precio * 23.40 AS PrecioPesos FROM Autobus
--Consulta D)
SELECT P.Nombre_Persona, E.Descripcion AS Estado_Nacimiento, A.Submarca FROM Persona P
INNER JOIN Automovil A ON P.ID_Persona = A.ID_Persona
INNER JOIN Estado_Nacimiento E ON P.Estado_Nacimiento = E.ID_Estado
WHERE A.Pais_Origen = 'México'
--Consulta E)
SELECT A.Marca, A.Submarca, A.Pais_Origen, P.Nombre_Persona, A.precio FROM Persona P
LEFT JOIN Automovil A ON A.ID_Persona = P.ID_Persona
WHERE P.Edad IN(32, 22, 45)
--Consulta F)
SELECT A.Marca, A.Submarca, P.Nombre_Persona FROM Persona P
LEFT JOIN Automovil A ON A.ID_Persona = P.ID_Persona
WHERE A.Marca IS NULL
--Consulta G)
SELECT P.Nombre_Persona, A.ID_auto, B.ID_bus, P.ID_Persona FROM Persona P
LEFT JOIN Automovil A ON A.ID_Persona = P.ID_Persona
LEFT JOIN Autobus B ON B.ID_Persona = P.ID_Persona
WHERE ID_Auto IS NOT NULL and ID_bus IS NOT NULL
--Consulta H)
SELECT P.Nombre_Persona,
COUNT(DISTINCT A.ID_auto) AS Cantidad_Autos,
COUNT(DISTINCT B.ID_bus) AS Cantidad_Autobuses
FROM Persona P
LEFT JOIN Automovil A ON A.ID_Persona = P.ID_Persona
LEFT JOIN Autobus B ON B.ID_Persona = P.ID_Persona
GROUP BY P.Nombre_Persona
--Consulta I)
SELECT P.Nombre_Persona, A.ID_auto, B.ID_bus, P.ID_Persona FROM Persona P
INNER JOIN Automovil A ON A.ID_Persona = P.ID_Persona
LEFT JOIN Autobus B ON B.ID_Persona = P.ID_Persona
--Consulta J)
SELECT P.Nombre_Persona, 
	   P.Municipio_Vive AS Direccion, 
	   E.Descripcion AS Estado_de_Nacimiento, 
	   A.Marca AS Automovil, 
	   A.Submarca, 
	   B.Marca AS Autobus, 
	   B.Submarca
FROM Persona P
INNER JOIN Estado_Nacimiento E ON E.ID_Estado = P.Estado_Nacimiento
INNER JOIN Automovil A ON P.ID_Persona = A.ID_Persona
INNER JOIN Autobus B ON P.ID_Persona = B.ID_Persona
WHERE P.Nombre_Persona = 'Roberto Yunes Corro'
--Consulta K)
SELECT ID_Persona, Nombre_Persona FROM Persona
WHERE ID_Persona NOT IN (SELECT ID_Persona FROM Automovil)
--Consulta L)
SELECT ID_Persona, Nombre_Persona AS Personas_con_Carro FROM Persona
WHERE ID_Persona IN (SELECT DISTINCT ID_Persona FROM Automovil)
--Consulta M)
SELECT * FROM Automovil
UNION
SELECT * FROM Autobus
--Consulta N)
SELECT Marca, Submarca, Pais_Origen FROM Automovil
UNION 
SELECT Marca, Submarca, Pais_Origen FROM Autobus










-- COMANDOS PARA PRUEBAS Y REVISION
SELECT * FROM sys.tables
SELECT * FROM Automovil
-- Desactivar temporalmente las validaciones de FOREIGN KEYS
ALTER TABLE Automovil NOCHECK CONSTRAINT FK_Automovil_Persona
ALTER TABLE Persona NOCHECK CONSTRAINT FK_Persona_Estado
ALTER TABLE Autobus NOCHECK CONSTRAINT FK_bus_Persona
-- Volver a activar las validaciones de FOREIGN KEYS
ALTER TABLE Automovil CHECK CONSTRAINT FK_Automovil_Persona;
ALTER TABLE Persona CHECK CONSTRAINT FK_Persona_Estado
ALTER TABLE Autobus CHECK CONSTRAINT FK_bus_Persona

--COMANDOS UTILES
--DROP DATABASE Ford_Mexico
--ALTER TABLE Autobus
--DROP CONSTRAINT FK_bus_Persona