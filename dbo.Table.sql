CREATE TABLE [dbo].[users] (
    [Id]       INT           IDENTITY (1, 1) NOT NULL,
    [username]     VARCHAR (100) NOT NULL,
    [password] VARCHAR (MAX) NOT NULL,
    PRIMARY KEY CLUSTERED ([Id] ASC),
    UNIQUE NONCLUSTERED ([username] ASC)
);

