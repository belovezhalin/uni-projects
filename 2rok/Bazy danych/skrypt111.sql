-- CREATE DATABASE Twich
CREATE TABLE [Tag] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [name] NCHAR(255) NOT NULL,
  [stream_id] BIGINT NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [User_Sub_m2m] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [streamer_id] BIGINT NOT NULL,
  [user_id] BIGINT NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Emoji] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [picture] NVARCHAR(255) NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Stream] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [title] NCHAR(255) NOT NULL,
  [description] NVARCHAR(255) NOT NULL,
  [start_date] DATETIME NOT NULL,
  [end_date] DATETIME NOT NULL,
  [status] NCHAR(32) NOT NULL,
  [chat_id] BIGINT UNIQUE,
  [views] BIGINT NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Category_Stream_m2m] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [category_id] BIGINT NOT NULL,
  [stream_id] BIGINT NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Category] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [name] NCHAR(255) NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Stream_User_m2m] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [stream_id] BIGINT NOT NULL,
  [user_id] BIGINT NOT NULL,
  [role_] SMALLINT NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Chat] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [theme_id] BIGINT NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Message] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [chat_id] BIGINT NOT NULL,
  [user_id] BIGINT NOT NULL,
  [date] DATETIME NOT NULL,
  [text] NVARCHAR(255) NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Theme] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [background] NVARCHAR(255) NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Liked_Stream_m2m] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [stream_id] BIGINT NOT NULL,
  [user_id] BIGINT NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Emoji_Message_m2m] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [message_id] BIGINT NOT NULL,
  [emoji_id] BIGINT NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Banned_User_m2m] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [user_id] BIGINT NOT NULL,
  [chat_id] BIGINT NOT NULL,
  [ban_time_begin] DATETIME NOT NULL,
  [ban_time_end] DATETIME NOT NULL,
  [ban_type] SMALLINT NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Restricted_Words] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [title] NCHAR(255) NOT NULL,
  [chat_id] BIGINT NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [User] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [username] NCHAR(255) NOT NULL,
  [password] NVARCHAR(255) NOT NULL,
  [profpic] NVARCHAR(255),
  [displayname] NCHAR(255) NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Pinned_Message] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [message_id] BIGINT UNIQUE NOT NULL,
  [pin_date] DATETIME NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Clip] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [stream_id] BIGINT NOT NULL,
  [user_id] BIGINT NOT NULL,
  [date_of_creation] DATETIME NOT NULL,
  [begin_time] TIME NOT NULL,
  [end_time] TIME NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Poll] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [chat_id] BIGINT NOT NULL,
  [question] NVARCHAR NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Poll_Option] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [poll_id] BIGINT NOT NULL,
  [text] NCHAR NOT NULL,
  [votes] BIGINT NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [User_Poll_Vote] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [poll_option_id] BIGINT NOT NULL,
  [user_id] BIGINT NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Report] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [user_id] BIGINT NOT NULL,
  [report_text] NVARCHAR NOT NULL,
  [report_reason_id] BIGINT NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Report_Reason] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [title] NCHAR NOT NULL,
  [punishment] SMALLINT NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [User_Bookmark] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [stream_id] BIGINT NOT NULL,
  [user_id] BIGINT NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Viewed_Clip_m2m] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [video_id] BIGINT NOT NULL,
  [user_id] BIGINT NOT NULL,
  [is_like] SMALLINT NOT NULL,
  PRIMARY KEY ([id])
)
GO

CREATE TABLE [Video] (
  [id] BIGINT IDENTITY(1,1) NOT NULL,
  [stream_id] BIGINT NOT NULL,
  [user_id] BIGINT NOT NULL,
  [date_of_creation] DATETIME NOT NULL,
  [begin_time] TIME NOT NULL,
  [end_time] TIME NOT NULL,
  [views] BIGINT NOT NULL,
  [likes] BIGINT NOT NULL,
  PRIMARY KEY ([id])
)
GO

ALTER TABLE [Liked_Stream_m2m] ADD CONSTRAINT [liked_stream_m2m_user_id_foreign] FOREIGN KEY ([user_id]) REFERENCES [User] ([id])
GO

ALTER TABLE [Liked_Stream_m2m] ADD CONSTRAINT [liked_stream_m2m_stream_id_foreign] FOREIGN KEY ([stream_id]) REFERENCES [Stream] ([id])
GO

ALTER TABLE [Category_Stream_m2m] ADD CONSTRAINT [category_stream_m2m_stream_id_foreign] FOREIGN KEY ([stream_id]) REFERENCES [Stream] ([id])
GO

ALTER TABLE [Stream] ADD CONSTRAINT [stream_chat_id_foreign] FOREIGN KEY ([chat_id]) REFERENCES [Chat] ([id])
GO

ALTER TABLE [Emoji_Message_m2m] ADD CONSTRAINT [emoji_message_m2m_emoji_id_foreign] FOREIGN KEY ([emoji_id]) REFERENCES [Emoji] ([id])
GO

ALTER TABLE [Banned_User_m2m] ADD CONSTRAINT [banned_user_m2m_user_id_foreign] FOREIGN KEY ([user_id]) REFERENCES [User] ([id])
GO

ALTER TABLE [Restricted_Words] ADD CONSTRAINT [restricted_words_chat_id_foreign] FOREIGN KEY ([chat_id]) REFERENCES [Chat] ([id])
GO

ALTER TABLE [Stream_User_m2m] ADD CONSTRAINT [stream_user_m2m_user_id_foreign] FOREIGN KEY ([user_id]) REFERENCES [User] ([id])
GO

ALTER TABLE [Category_Stream_m2m] ADD CONSTRAINT [category_stream_m2m_category_id_foreign] FOREIGN KEY ([category_id]) REFERENCES [Category] ([id])
GO

ALTER TABLE [Tag] ADD CONSTRAINT [tag_stream_id_foreign] FOREIGN KEY ([stream_id]) REFERENCES [Stream] ([id])
GO

ALTER TABLE [Banned_User_m2m] ADD CONSTRAINT [banned_user_m2m_chat_id_foreign] FOREIGN KEY ([chat_id]) REFERENCES [Chat] ([id])
GO

ALTER TABLE [Message] ADD CONSTRAINT [message_chat_id_foreign] FOREIGN KEY ([chat_id]) REFERENCES [Chat] ([id])
GO

ALTER TABLE [User_Sub_m2m] ADD CONSTRAINT [user_sub_m2m_streamer_id_foreign] FOREIGN KEY ([streamer_id]) REFERENCES [User] ([id])
ALTER TABLE [User_Sub_m2m] ADD CONSTRAINT [uniqueSub] UNIQUE(streamer_id,user_id)
GO

ALTER TABLE [Chat] ADD CONSTRAINT [chat_theme_id_foreign] FOREIGN KEY ([theme_id]) REFERENCES [Theme] ([id])
GO

ALTER TABLE [Emoji_Message_m2m] ADD CONSTRAINT [emoji_message_m2m_message_id_foreign] FOREIGN KEY ([message_id]) REFERENCES [Message] ([id])
GO

ALTER TABLE [Message] ADD CONSTRAINT [message_user_id_foreign] FOREIGN KEY ([user_id]) REFERENCES [User] ([id])
GO

ALTER TABLE [Stream_User_m2m] ADD CONSTRAINT [stream_user_m2m_stream_id_foreign] FOREIGN KEY ([stream_id]) REFERENCES [Stream] ([id])
GO

ALTER TABLE [User_Sub_m2m] ADD CONSTRAINT [user_sub_m2m_user_id_foreign] FOREIGN KEY ([user_id]) REFERENCES [User] ([id])
GO

ALTER TABLE [Pinned_Message] ADD CONSTRAINT [pinned_message_message_id_foreign] FOREIGN KEY ([message_id]) REFERENCES [Message] ([id])
GO

ALTER TABLE [Clip] ADD CONSTRAINT [clip_stream_id_stream_foreign] FOREIGN KEY ([stream_id]) REFERENCES [Stream] ([id])
GO

ALTER TABLE [Clip] ADD CONSTRAINT [clip_user_id_foreign] FOREIGN KEY ([user_id]) REFERENCES [User] ([id])
GO

ALTER TABLE [Poll] ADD CONSTRAINT [poll_chat_id_foreign] FOREIGN KEY ([chat_id]) REFERENCES [Chat] ([id])
GO

ALTER TABLE [Poll_Option] ADD CONSTRAINT [poll_option_poll_id_foreign] FOREIGN KEY ([poll_id]) REFERENCES [Poll] ([id])
GO

ALTER TABLE [User_Poll_Vote] ADD CONSTRAINT [user_poll_votes_poll_option_id_foreign] FOREIGN KEY ([poll_option_id]) REFERENCES [Poll_Option] ([id])
GO

ALTER TABLE [User_Poll_Vote] ADD CONSTRAINT [user_poll_votes_user_id_foreign] FOREIGN KEY ([user_id]) REFERENCES [User] ([id])
GO

ALTER TABLE [Report] ADD CONSTRAINT [report_user_id_foreign] FOREIGN KEY ([user_id]) REFERENCES [User] ([id])
GO

ALTER TABLE [Report] ADD CONSTRAINT [report_report_reason_id_foreign] FOREIGN KEY ([report_reason_id]) REFERENCES [Report_Reason] ([id])
GO

ALTER TABLE [User_Bookmark] ADD CONSTRAINT [user_bookmark_user_id_foreign] FOREIGN KEY ([user_id]) REFERENCES [User] ([id])
GO

ALTER TABLE [User_Bookmark] ADD CONSTRAINT [user_bookmark_stream_id_foreign] FOREIGN KEY ([stream_id]) REFERENCES [Stream] ([id])
GO

ALTER TABLE [Viewed_Clip_m2m] ADD CONSTRAINT [liked_clip_m2m_clip_id_foreign] FOREIGN KEY ([video_id]) REFERENCES [Video] ([id])
GO

ALTER TABLE [Viewed_Clip_m2m] ADD CONSTRAINT [liked_clip_m2m_user_id_foreign] FOREIGN KEY ([user_id]) REFERENCES [User] ([id])
GO


CREATE TRIGGER StreamUpdateViews ON Stream_User_m2m
AFTER INSERT AS
BEGIN
  
  DECLARE @currentId INT


  DECLARE InsertedIds CURSOR FOR 
  SELECT stream_id FROM inserted
  FOR READ ONLY


  OPEN InsertedIds

  FETCH InsertedIds INTO @currentId

  WHILE(@@FETCH_STATUS=0)
  BEGIN
    UPDATE Stream
      SET views = views+1
      WHERE id = @currentId
    FETCH InsertedIds INTO @currentId
  END
  CLOSE InsertedIds
  DEALLOCATE InsertedIds
END


GO
CREATE TRIGGER SubscriptionCheck ON User_Sub_m2m
INSTEAD OF INSERT 
AS
BEGIN
  DECLARE @currStreamerId BIGINT
  DECLARE @currViewerId BIGINT

  DECLARE insertTrack CURSOR FOR
  SELECT streamer_id, user_id FROM inserted 
  FOR READ ONLY

  OPEN insertTrack
  FETCH insertTrack INTO @currStreamerId, @currViewerId

  WHILE(@@FETCH_STATUS = 0)
  BEGIN
    IF(@currStreamerId = @currViewerId)
       BEGIN
        DECLARE @ErrorMessage NVARCHAR(255)
        SET @ErrorMessage = FORMATMESSAGE(N'Self subscription is prohibited (error with ids %I64d and %I64d)', @currStreamerId, @currViewerId)
        RAISERROR(@ErrorMessage, 16, 1)
      END
    FETCH insertTrack INTO @currStreamerId, @currViewerId
  END
  CLOSE insertTrack
  DEALLOCATE insertTrack

  INSERT INTO [User_Sub_m2m](streamer_id,user_id) SELECT streamer_id,user_id FROM inserted

END

GO
CREATE TRIGGER ViewUpdateLikeCheck ON Viewed_Clip_m2m
INSTEAD OF INSERT 
AS
BEGIN
  DECLARE currData CURSOR FOR
  SELECT video_id, user_id, is_like FROM inserted

  OPEN currData

  DECLARE @currVidId BIGINT
  DECLARE @currUserId BIGINT
  DECLARE @isLike SMALLINT

  FETCH currData INTO @currVidId, @currUserId,@isLike

  WHILE(@@FETCH_STATUS = 0)
    BEGIN
      IF EXISTS(SELECT id FROM Viewed_Clip_m2m WHERE video_id=@currVidId AND user_id=@currUserId)
        BEGIN
          DECLARE @isLikePrev SMALLINT
          SET @isLikePrev = (SELECT is_like FROM Viewed_Clip_m2m WHERE video_id=@currVidId AND user_id=@currUserId)
          IF (@isLike = 1 AND @isLikePrev = 0)
            UPDATE Video SET likes=likes+1 WHERE id = @currVidId
          UPDATE Video SET views=views+1 WHERE id = @currVidId
        END
      ELSE
        BEGIN
        IF @isLike = 1
          UPDATE Video SET likes=likes+1 WHERE id = @currVidId
        INSERT INTO Viewed_Clip_m2m(video_id, user_id, is_like) VALUES
        (@currVidId,@currUserId,@isLike)
        END
          FETCH currData INTO @currVidId, @currUserId,@isLike
    END
END

GO

CREATE TRIGGER EnforceStreamLimits
ON [Stream_User_m2m]
AFTER INSERT, UPDATE
AS
BEGIN
    --Zamiast 15000 moze być wyliczona maks ilość osób których moze znieść serwer
    IF (SELECT COUNT(*) FROM [Stream_User_m2m] WHERE stream_id = (SELECT stream_id FROM INSERTED)) > 15000
    BEGIN
        RAISERROR('Cannot exceed 100 users in a stream.', 16, 1);
        ROLLBACK;
    END
END

GO

CREATE TRIGGER ArchiveStreams
ON Stream AFTER INSERT AS
UPDATE Stream SET status = 'Archived' WHERE DATEDIFF(DAY, end_date, GETDATE()) >= 30;

GO

CREATE TRIGGER PreventDuplicateStreams
ON Stream
INSTEAD OF INSERT
AS
BEGIN
    DECLARE currStream CURSOR FOR
    SELECT title FROM Stream

    OPEN currStream
    DECLARE @currTitle NVARCHAR(256)
    FETCH currStream INTO @currTitle

    WHILE(@@FETCH_STATUS = 0)
      BEGIN
      IF EXISTS (SELECT * FROM Stream WHERE title = @currTitle AND [status] = 'Active')
        BEGIN
            RAISERROR('Duplicate stream detected.', 16, 1);
            RETURN;
        END
      ELSE
        BEGIN
            INSERT INTO Stream (title, description, start_date, end_date, status, chat_id, views)
            SELECT title, description, start_date, end_date, status, chat_id, views FROM inserted;
        END
      FETCH currStream INTO @currTitle
    END
END



INSERT INTO "User" ( "username", "password", "profpic", "displayname") VALUES 
('john_doe', 'password1', 'john_doe_pic.jpg', 'John Doe'),
('alice_smith', 'password2', 'alice_smith_pic.jpg', 'Alice Smith'),
('mark_jones', 'password3', 'mark_jones_pic.jpg', 'Mark Jones'),
('laura_miller', 'password4', 'laura_miller_pic.jpg', 'Laura Miller'),
('david_clark', 'password5', 'david_clark_pic.jpg', 'David Clark'),
('emma_brown', 'password6', 'emma_brown_pic.jpg', 'Emma Brown'),
('michael_white', 'password7', 'michael_white_pic.jpg', 'Michael White'),
('olivia_taylor', 'password8', 'olivia_taylor_pic.jpg', 'Olivia Taylor'),
('ryan_thomas', 'password9', 'ryan_thomas_pic.jpg', 'Ryan Thomas'),
( 'sophia_hall', 'password10', 'sophia_hall_pic.jpg', 'Sophia Hall'),
( 'jackson_baker', 'password11', 'jackson_baker_pic.jpg', 'Jackson Baker'),
( 'claire_hill', 'password12', 'claire_hill_pic.jpg', 'Claire Hill'),
( 'nathan_wilson', 'password13', 'nathan_wilson_pic.jpg', 'Nathan Wilson'),
( 'chloe_martin', 'password14', 'chloe_martin_pic.jpg', 'Chloe Martin'),
( 'brian_walker', 'password15', 'brian_walker_pic.jpg', 'Brian Walker'),
( 'emily_cooper', 'password16', 'emily_cooper_pic.jpg', 'Emily Cooper'),
( 'samuel_robinson', 'password17', 'samuel_robinson_pic.jpg', 'Samuel Robinson'),
( 'sara_adams', 'password18', 'sara_adams_pic.jpg', 'Sara Adams'),
( 'robert_fisher', 'password19', 'robert_fisher_pic.jpg', 'Robert Fisher'),
( 'jessica_wright', 'password20', 'jessica_wright_pic.jpg', 'Jessica Wright');

INSERT INTO [Theme] ([background]) VALUES 
('theme1_background.jpg'),
('theme2_background.jpg'),
('theme3_background.jpg'),
('theme4_background.jpg'),
('theme5_background.jpg');

INSERT INTO [Chat] ([theme_id]) VALUES 
(1),
(2),
(3),
(4),
(5),
(1),
(2),
(3),
(4),
(5),
(1),
(2),
(3),
(4),
(5),
(1),
(2),
(3),
(4),
(5);

INSERT INTO [Stream] ([title], [description], [start_date], [end_date], [status], [chat_id], [views]) VALUES 
('Gaming Live', 'Join me for a gaming session!', '2024-01-28 12:00:00', '2024-01-28 14:00:00', 1, 6, 0),
('Cooking Show', 'Learn how to make delicious recipes!', '2024-02-05 18:30:00', '2024-02-05 20:30:00', 1, 2, 0),
('Tech Talk', 'Discussing the latest in technology', '2024-02-10 15:00:00', '2024-02-10 17:00:00', 1, 3, 0),
('Fitness Challenge', 'Lets work out together!', '2024-02-15 07:00:00', '2024-02-15 08:30:00', 1, 4, 0),
('Music Jam', 'Live music performance and Q&A', '2024-02-20 20:00:00', '2024-02-20 22:00:00', 1, 5, 0),
('Art Showcase', 'Showcasing my latest artworks', '2024-02-25 14:00:00', '2024-02-25 16:00:00', 1, 6, 0),
('Book Club', 'Discussing our favorite books', '2024-03-02 19:00:00', '2024-03-02 21:00:00', 1, 7, 0),
('Travel Vlog', 'Exploring new destinations live', '2024-03-08 10:00:00', '2024-03-08 12:30:00', 1, 8, 0),
('DIY Workshop', 'Creating handmade crafts together', '2024-03-14 16:30:00', '2024-03-14 18:30:00', 1, 9, 0),
('Coding Session', 'Coding and answering questions', '2024-03-20 13:00:00', '2024-03-20 15:00:00', 1, 6, 0),
('Language Learning', 'Practicing a new language', '2024-03-25 17:00:00', '2024-03-25 19:00:00', 1, 6, 0),
('Movie Night', 'Watching a movie and discussing', '2024-03-30 20:30:00', '2024-03-30 23:00:00', 1, 2, 0),
('Science Talk', 'Exploring fascinating scientific topics', '2024-04-05 14:00:00', '2024-04-05 16:00:00', 1, 3, 0),
('Fashion Show', 'Showcasing the latest fashion trends', '2024-04-10 18:00:00', '2024-04-10 20:00:00', 1, 4, 0),
('Pet Parade', 'Introducing my adorable pets', '2024-04-15 12:00:00', '2024-04-15 14:30:00', 1, 5, 0),
('Gardening Tips', 'Sharing gardening tips and tricks', '2024-04-20 16:00:00', '2024-04-20 18:00:00', 1, 6, 0),
('Yoga Session', 'Relaxing yoga session for everyone', '2024-04-25 08:30:00', '2024-04-25 10:00:00', 1, 7, 0),
('Motivational Talk', 'Inspiring and motivating discussion', '2024-04-30 19:00:00', '2024-04-30 21:00:00', 1, 8, 0),
('Home Renovation', 'Renovating my living space live', '2024-05-05 15:00:00', '2024-05-05 17:30:00', 1, 9, 0),
('Car Enthusiast Meetup', 'Discussing and showcasing cars', '2024-05-10 18:00:00', '2024-05-10 20:30:00', 1, 20, 0);



INSERT INTO [Stream_User_m2m] ([stream_id], [user_id], [role_]) VALUES 
(1, 6, 1),
(1, 2, 3),
(1, 3, 2),
(2, 4, 1),
(2, 5, 2),
(2, 6, 3),
(3, 7, 1),
(3, 8, 2),
(3, 9, 3),
(4, 10, 1),
(4, 11, 2),
(4, 12, 3),
(5, 13, 1),
(5, 14, 2),
(5, 15, 3),
(6, 16, 1),
(6, 17, 2),
(6, 18, 3),
(7, 19, 1),
(7, 20, 2),
(8, 1, 3),
(8, 2, 1),
(8, 3, 2),
(9, 4, 3),
(9, 5, 1),
(9, 6, 2),
(10, 7, 3),
(10, 8, 1),
(10, 9, 2),
(11, 6, 3),
(11, 6, 6),
(11, 2, 5),
(12, 13, 2),
(12, 14, 1),
(12, 15, 2),
(13, 16, 3),
(13, 17, 1),
(13, 18, 2),
(14, 19, 3),
(14, 20, 1),
(14, 1, 2),
(15, 2, 3),
(15, 3, 1),
(15, 4, 2),
(16, 5, 3),
(16, 9, 1),
(16, 7, 2),
(17, 8, 3),
(17, 9, 1),
(17, 10, 2),
(18, 11, 3),
(18, 12, 1),
(18, 13, 2),
(19, 14, 3),
(19, 15, 1),
(19, 16, 2),
(20, 17, 3),
(20, 18, 1),
(16, 5, 6),
(16, 9, 8),
(16, 7, 20),
(17, 8, 10),
(16, 9, 15),
(17, 10, 20),
(18, 11, 4),
(18, 12, 2),
(18, 13, 2),
(19, 14, 4),
(19, 15, 2),
(19, 16, 3),
(19, 17, 4),
(19, 18, 2),
(20, 19, 3);


INSERT INTO [Restricted_Words] ([title], [chat_id]) VALUES 
('Profanity', 1),
('Inappropriate', 2),
('Offensive', 3),
('HateSpeech', 4),
('Spam', 5),
('Bullying', 6),
('Illegal', 7),
('Racist', 8),
('Explicit', 9),
('Harassment', 10),
('Disallowed', 11),
('Obscene', 12),
('Threatening', 13),
('Insulting', 14),
('Vulgar', 15),
('Abusive', 4),
('Harmful', 17),
('Xenophobic', 18),
('Misleading', 19),
('Forgery', 20),
('Fraudulent', 1),
('Deceptive', 2),
('Manipulative', 3),
('Impersonation', 4),
('Disruptive', 2),
('Intrusive', 4),
('Unlawful', 6),
('Prohibited', 7),
('Restricted', 5),
('Forbidden', 10);


INSERT INTO [Tag] ([name], [stream_id]) VALUES 
('GamingLive', 1),
('CookingShow', 2),
('TechTalk', 3),
('FitnessChallenge', 4),
('MusicJam', 5),
('ArtShowcase', 6),
('BookClub', 7),
('TravelVlog', 8),
('DIYWorkshop', 9),
('CodingSession', 10),
('LanguageLearning', 11),
('MovieNight', 12),
('ScienceTalk', 13),
('FashionShow', 14),
('PetParade', 15),
('GardeningTips', 16),
('YogaSession', 17),
('MotivationalTalk', 18),
('HomeRenovation', 19),
('CarEnthusiastMeetup', 20),
('HealthTips', 1),
('EducationalContent', 2),
('Entertainment', 3),
('SportsTalk', 4),
('CookingTips', 5),
('Photography', 6),
('BusinessTalk', 7),
('FinanceDiscussion', 8),
('NatureExploration', 9),
('TechNews', 10);


INSERT INTO [Category] ([name]) VALUES 
('Technology'),
('Food'),
('Health'),
('Education'),
('Gaming'),
('Travel'),
('Sports'),
('Music'),
('Art'),
('Fashion'),
('Finance'),
('Science'),
('Fitness'),
('Movies'),
('Business');

INSERT INTO [Category_Stream_m2m] ([category_id], [stream_id]) VALUES 
(1, 6),
(7, 5),
(3, 2),
(7, 8),
(5, 1),
(6, 9),
(7, 10),
(7, 10),
(9, 5),
(10, 13),
(11, 6),
(2, 14),
(13, 15),
(13, 10),
(15, 11),
(10, 6),
(2, 17),
(3, 18),
(4, 19),
(5, 20),
(6, 1),
(7, 2),
(8, 3),
(8, 4),
(10, 5),
(8, 6),
(12, 7),
(12, 8),
(14, 9),
(15, 10);


INSERT INTO [User_Bookmark] ([stream_id], [user_id]) VALUES 
(1, 6),
(2, 5),
(3, 2),
(4, 7),
(5, 1),
(6, 9),
(7, 10),
(8, 10),
(9, 5),
(10, 13),
(11, 6),
(12, 14),
(13, 11),
(14, 10),
(15, 11),
(16, 18),
(17, 19),
(18, 20),
(19, 15),
(20, 18);


INSERT INTO [Liked_Stream_m2m] ([stream_id], [user_id]) VALUES 
(1, 6),
(1, 5),
(3, 2),
(1, 7),
(5, 1),
(6, 9),
(7, 10),
(2, 10),
(9, 5),
(10, 13),
(1, 6),
(2, 14),
(13, 15),
(14, 10),
(15, 11),
(12, 18),
(12, 19),
(17, 20),
(12, 15),
(20, 18),
(1, 5),
(12, 5),
(3, 2),
(4, 7),
(2, 1),
(6, 9),
(15, 10),
(8, 7),
(9, 5),
(10, 13),
(1, 6),
(17, 12),
(13, 7),
(14, 10),
(15, 11),
(15, 16),
(17, 19),
(15, 20),
(15, 19),
(20, 18);


INSERT INTO [User_Sub_m2m] ([streamer_id], [user_id]) VALUES 
(1, 6),
(1, 5),
(3, 2),
(1, 7),
(5, 1),
(6, 10),
(7, 10),
(8, 10),
(8, 5),
(11, 6),
(11, 5),
(11, 2),
(13, 15),
(11, 4),
(15, 11);

INSERT INTO [Report_Reason] ([title], [punishment]) VALUES 
('Inappropriate content', 1),
('Violent behavior', 2),
('Privacy violation', 3),
('Unwanted advertisements', 4),
('Disruptive behavior', 5),
('False information', 6),
('Abuse of platform features', 7),
('Discrimination', 8),
('Cyberbullying', 9),
('Security threat', 10);

INSERT INTO [Report] ([user_id], [report_text], [report_reason_id]) VALUES 
(2, 'Spamming content', 2),
(3, 'Harassment towards users', 3),
(5, 'Violating community guidelines', 4),
(5, 'Explicit content', 5),
(6, 'Bullying other users', 6),
(5, 'Impersonation', 7),
(8, 'Misinformation spreading', 8)


INSERT INTO [Message] ([chat_id], [user_id], [date], [text]) VALUES 
(1, 6, '2024-01-27 10:00:00', 'Hey everyone! Welcome to the stream!'),
(1, 2, '2024-01-27 10:05:00', 'Hello streamer! Excited for today’s content.'),
(1, 3, '2024-01-27 10:10:00', 'What game are we playing today?'),
(1, 4, '2024-01-27 10:15:00', 'Today we re diving into some retro gaming!'),
(1, 5, '2024-01-27 10:20:00', 'Nice! I love retro games. Any specific title?'),
(1, 6, '2024-01-27 10:25:00', 'We ll be starting with Super Mario Bros. and then move on to Zelda!'),
(1, 6, '2024-01-27 10:30:00', 'Awesome choices! Cant wait.'),
(1, 7, '2024-01-27 10:35:00', 'Don t forget to hit the like button and subscribe if you enjoy the stream!'),
(1, 8, '2024-01-27 10:40:00', 'Just shared the stream on my socials. Lets get more viewers in here!'),
(1, 9, '2024-01-27 10:45:00', 'Thanks for the shoutout!'),
(1, 6, '2024-01-27 10:50:00', 'This is my first time here. What s the stream about?'),
(1, 6, '2024-01-27 10:55:00', 'We play a variety of games and discuss different topics. It s a chill community.'),
(1, 6, '2024-01-27 11:00:00', 'I love the community vibe. Count me in!'),
(1, 2, '2024-01-27 11:05:00', 'Who else is here from last week’s stream?'),
(1, 3, '2024-01-27 11:10:00', 'I am! Last week s stream was epic.'),
(1, 4, '2024-01-27 11:15:00', 'Glad to have you all back! Let s make today even better.'),
(1, 5, '2024-01-27 11:20:00', 'Do you take game requests from viewers?'),
(1, 6, '2024-01-27 11:25:00', 'Absolutely! Drop your suggestions, and we ll consider them for future streams.'),
(1, 6, '2024-01-27 11:30:00', 'Can we do a horror game next time? That would be awesome!'),
(1, 7, '2024-01-27 11:35:00', 'I m all for horror games! It s going to be a scream.'),
(1, 8, '2024-01-27 11:40:00', 'Count me out for horror games. I m too scared!'),
(1, 6, '2024-01-27 11:45:00', 'Don t worry, we ll mix it up. Something for everyone!'),
(1, 9, '2024-01-27 11:50:00', 'I m having a blast! The chat is as entertaining as the games.'),
(1, 20, '2024-01-27 11:55:00', 'You guys are the best! Thanks for making this community awesome.');


INSERT INTO [Emoji] ([picture]) VALUES 
('https://example.com/emoji1.png'),
('https://example.com/emoji2.png'),
('https://example.com/emoji3.png'),
('https://example.com/emoji4.png'),
('https://example.com/emoji5.png'),
('https://example.com/emoji6.png'),
('https://example.com/emoji7.png'),
('https://example.com/emoji8.png'),
('https://example.com/emoji9.png'),
('https://example.com/emoji10.png');

INSERT INTO [Emoji_Message_m2m] ([message_id], [emoji_id]) VALUES 
(1, 6),
(2, 5),
(3, 2),
(4, 7),
(5, 1),
(6, 9),
(7, 10),
(8, 10),
(9, 5),
(10, 9),
(11, 6),
(12, 5),
(13, 2),
(14, 7),
(15, 1);

INSERT INTO [Pinned_Message] ([message_id], [pin_date]) VALUES 
(1, '2024-01-27 14:30:00'),
(2, '2024-01-27 15:00:00'),
(3, '2024-01-27 16:30:00'),
(4, '2024-01-27 17:15:00'),
(5, '2024-01-27 18:45:00');

INSERT INTO [Poll] ([chat_id], [question]) VALUES 
(1, 'Which game should we play next?'),
(2, 'What s your favorite genre of music?'),
(3, 'Who is your favorite superhero?'),
(4, 'What s your go-to snack during a stream?'),
(5, 'Which day is best for community events?');

-- Poll 1 Options
INSERT INTO [Poll_Option] ([poll_id], [text], [votes]) VALUES 
(1, 'Fortnite', 0),
(1, 'Minecraft', 0),
(1, 'Among Us', 0),
(1, 'Apex Legends', 0);

-- Poll 2 Options
INSERT INTO [Poll_Option] ([poll_id], [text], [votes]) VALUES 
(2, 'Rock', 0),
(2, 'Pop', 0),
(2, 'Hip Hop', 0),
(2, 'Electronic', 0);

-- Poll 3 Options
INSERT INTO [Poll_Option] ([poll_id], [text], [votes]) VALUES 
(3, 'Superman', 0),
(3, 'Batman', 0),
(3, 'Spider-Man', 0),
(3, 'Wonder Woman', 0);

-- Poll 4 Options
INSERT INTO [Poll_Option] ([poll_id], [text], [votes]) VALUES 
(4, 'Pizza', 0),
(4, 'Popcorn', 0),
(4, 'Chips', 0),
(4, 'Candy', 0);

-- Poll 5 Options
INSERT INTO [Poll_Option] ([poll_id], [text], [votes]) VALUES 
(5, 'Monday', 0),
(5, 'Wednesday', 0),
(5, 'Friday', 0),
(5, 'Saturday', 0);


-- User 1 Votes
INSERT INTO [User_Poll_Vote] ([poll_option_id], [user_id]) VALUES 
(1, 6),
(2, 1),
(3, 1);

-- User 2 Votes
INSERT INTO [User_Poll_Vote] ([poll_option_id], [user_id]) VALUES 
(1, 2),
(4, 2),
(5, 2);

-- User 3 Votes
INSERT INTO [User_Poll_Vote] ([poll_option_id], [user_id]) VALUES 
(3, 2),
(6, 3),
(7, 3);

-- User 4 Votes
INSERT INTO [User_Poll_Vote] ([poll_option_id], [user_id]) VALUES 
(8, 4),
(9, 4),
(10, 4);

-- User 5 Votes
INSERT INTO [User_Poll_Vote] ([poll_option_id], [user_id]) VALUES 
(11, 5),
(12, 5),
(1, 5);

-- User 6 Votes
INSERT INTO [User_Poll_Vote] ([poll_option_id], [user_id]) VALUES 
(2, 6),
(3, 6),
(4, 6);


INSERT INTO [Banned_User_m2m] ([user_id], [chat_id], [ban_time_begin], [ban_time_end], [ban_type]) VALUES 
(1, 6, '2024-01-27 16:00:00', '2024-01-27 18:00:00', 1),
(2, 1, '2024-01-27 14:30:00', '2024-01-27 15:30:00', 2),
(3, 2, '2024-01-27 12:00:00', '2024-01-27 13:00:00', 1),
(4, 2, '2024-01-27 17:45:00', '2024-01-27 19:45:00', 3),
(5, 3, '2024-01-27 15:00:00', '2024-01-27 16:00:00', 2);


INSERT INTO [Clip] ([stream_id], [user_id], [date_of_creation], [begin_time], [end_time]) VALUES 
(1, 6, '2024-01-27', '15:30:00', '15:45:00'),
(2, 5, '2024-01-28', '18:00:00', '18:15:00'),
(3, 2, '2024-01-29', '21:45:00', '22:00:00'),
(1, 4, '2024-01-30', '12:30:00', '12:45:00'),
(2, 5, '2024-01-31', '16:15:00', '16:30:00');


INSERT INTO [Liked_Clip_m2m] ([clip_id], [user_id]) VALUES 
(1, 6),
(2, 5),
(3, 2),
(4, 7),
(5, 1),
(1, 6),
(2, 5),
(3, 2);

GO
CREATE PROC NUMBER_OF_FOLLOWERS_OF(@streamer_id BIGINT, @num BIGINT OUTPUT)
AS
SELECT @num=COUNT(*)
FROM [User_Sub_m2m]
WHERE streamer_id=@streamer_id
GO
DECLARE @num BIGINT
EXEC NUMBER_OF_FOLLOWERS_OF 11, @num OUTPUT
PRINT @num
GO

CREATE PROC PRINT_FOLLOWERS_OF(@streamer_id BIGINT)
AS
SELECT user_id
FROM [User_Sub_m2m]
WHERE streamer_id=@streamer_id
GO
EXEC PRINT_FOLLOWERS_OF 11
GO

CREATE PROC NUMBER_OF_FOLLOWINGS_OF(@user_id BIGINT, @num BIGINT OUTPUT)
AS
SELECT @num=COUNT(*)
FROM [User_Sub_m2m]
WHERE user_id=@user_id
GO
DECLARE @num BIGINT
EXEC NUMBER_OF_FOLLOWINGS_OF 7, @num OUTPUT
PRINT @num
GO

CREATE PROC PRINT_FOLLOWINGS_OF(@user_id BIGINT)
AS
SELECT streamer_id
FROM [User_Sub_m2m]
WHERE user_id=@user_id
GO
EXEC PRINT_FOLLOWINGS_OF 1

GO
CREATE PROCEDURE GetTopViewedStreamers AS
BEGIN
    SELECT TOP 5 U.id, U.username, SUM(S.views) AS Views_Number
    FROM [User] U
    LEFT JOIN Stream S ON U.id = S.id
    GROUP BY U.id, U.username
    ORDER BY Views_Number DESC;
END;
GO

EXEC GetTopViewedStreamers

GO


CREATE VIEW PopularCategories AS
SELECT
    C.id AS Category_ID,
    C.name AS Category_Name,
    COUNT(CS.stream_id) AS Stream_Count
FROM Category C
LEFT JOIN Category_Stream_m2m CS ON C.id = CS.category_id
GROUP BY C.id, C.name
GO

SELECT *
FROM PopularCategories
ORDER BY Stream_Count DESC

GO

CREATE VIEW TopStreamers AS
SELECT U.id, U.username, COUNT(S.streamer_id) AS Subscribtion_Number
FROM [User] U
LEFT JOIN User_Sub_m2m S ON U.id = S.streamer_id
GROUP BY U.id, U.username
-- ORDER BY COUNT(S.streamer_id)
GO

SELECT TOP 3 *
FROM TopStreamers
ORDER BY Subscribtion_Number DESC

GO

CREATE VIEW TopStreams AS
    SELECT S.id, S.title, COUNT(*) AS Likes_Number 
    FROM Stream S
    LEFT JOIN Liked_Stream_m2m L ON S.id = L.stream_id
    GROUP BY S.id, S.title
GO
SELECT  TOP 5 *
FROM TopStreams
ORDER BY Likes_Number DESC

GO


CREATE View PollsStats
AS
SELECT p.id, p.question, po.text, COUNT(upv.poll_option_id) votes
    FROM Poll p JOIN Poll_Option  po ON p.id=po.poll_id LEFT JOIN User_Poll_Vote upv ON po.id=upv.poll_option_id
    GROUP BY po.id,po.text, p.id, p.question
GO

CREATE FUNCTION CalculatePollWin(@poll_id bigint)
RETURNS @tab TABLE (id bigint, question NVARCHAR(255), [text] NVARCHAR(255), votes bigint)
AS
BEGIN
        INSERT INTO @tab
        SELECT TOP 1 ps.*
        FROM PollsStats ps
        WHERE ps.id=@poll_id
        ORDER BY votes DESC

RETURN
END

GO 

SELECT *
FROM dbo.CalculatePollWin(1)

GO 


CREATE FUNCTION SubsOfSubs(@streamer_id bigint)
RETURNS @tab TABLE (follower_id bigint, streamer_id bigint, Distance bigint)
BEGIN
;WITH CTE_SubsOfSubs (follower_id, streamer_id, Distance)
AS
(
SELECT user_id, streamer_id, 1
FROM User_Sub_m2m
WHERE streamer_id=@streamer_id
UNION ALL
SELECT P.user_id, CTE_SubsOfSubs.streamer_id, Distance + 1
FROM User_Sub_m2m AS P JOIN CTE_SubsOfSubs ON P.streamer_id = CTE_SubsOfSubs.follower_id
AND P.user_id IS NOT NULL AND P.user_id <>@streamer_id
)
INSERT INTO @tab
SELECT * FROM CTE_SubsOfSubs
RETURN
END

GO

SELECT *
FROM dbo.SubsOFSubs(5)
    
GO

CREATE VIEW Emoji_stats
AS
SELECT e.id, COUNT(em.message_id) Messages_number
FROM Emoji e LEFT JOIN Emoji_Message_m2m em ON e.id=em.emoji_id
GROUP BY e.id

GO

SELECT  TOP 5 *
FROM Emoji_stats
ORDER BY Messages_number DESC

GO

CREATE FUNCTION PinnedMesagesInOrder(@chat_id int)
RETURNS @tab TABLE (message_text NVARCHAR(255), pin_date DATETIME)
BEGIN
INSERT INTO @tab 
SELECT m.text, pm.pin_date
FROM [Message] m JOIN Pinned_Message pm ON m.id=pm.message_id
WHERE m.chat_id=@chat_id
ORDER BY pm.pin_date DESC
RETURN 
END

GO
SELECT *
FROM dbo.PinnedMesagesInOrder(1)

GO
CREATE VIEW BannedUsers AS
SELECT
    BU.user_id AS banned_user_id,
    U.username AS banned_username,
    BU.chat_id,
    BU.ban_time_begin,
    BU.ban_time_end,
    BU.ban_type
FROM
    Banned_User_m2m BU
JOIN [User] U ON BU.user_id = U.id
JOIN Chat C ON BU.chat_id = C.id
GO
SELECT * FROM BannedUsers
GO

CREATE VIEW ActiveStreams AS
SELECT
    S.id,
    S.title,
    U.username AS streamer_username,
    S.start_date,
    S.end_date,
    S.views
FROM
    Stream S
JOIN Stream_User_m2m SU ON S.id = SU.stream_id
JOIN [User] U ON SU.user_id = U.id
WHERE S.status = 1
GO
SELECT * FROM ActiveStreams
ORDER BY views DESC
GO

CREATE VIEW ReportedUsers AS
SELECT
    RU.user_id,
    U.username,
    R.title AS report_reason
FROM
    Report RU
JOIN [User] U ON RU.user_id = u.id
JOIN Report_Reason R ON RU.report_reason_id = R.id
GO
SELECT * FROM ReportedUsers
GO


CREATE VIEW TopClips AS
SELECT
    C.user_id AS clip_creator_id,
    U.username AS clip_creator_username,
    C.stream_id,
    S.title AS stream_title,
    C.date_of_creation,
    C.begin_time,
    C.end_time,
    COUNT(LC.user_id) AS likes_count
FROM
    Clip C
JOIN [User] U ON C.user_id = U.id
JOIN Liked_Clip_m2m LC ON C.id = LC.clip_id
JOIN Stream S ON C.stream_id = S.id
GROUP BY
    C.user_id,
    U.username,
    C.stream_id,
    S.title,
    C.date_of_creation,
    C.begin_time,
    C.end_time
GO 


SELECT TOP 5 * FROM TopClips
ORDER BY likes_count DESC
GO
